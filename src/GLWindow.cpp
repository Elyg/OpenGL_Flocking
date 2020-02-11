#include "GLWindow.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QGuiApplication>
#include <ngl/Camera.h>
#include <ngl/Light.h>
#include <ngl/Material.h>
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include <ngl/Random.h>
#include <boost/foreach.hpp>
#include <ngl/Transformation.h>
#include <ngl/BBox.h>
#include <boid.h>
#include <ngl/NGLStream.h>
#include "fstream"

//----------------------------------------------------------------------------------------------------------------------
/// @brief the increment for x/y translation with mouse movement
//----------------------------------------------------------------------------------------------------------------------
const static float INCREMENT=0.01f;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the increment for the wheel zoom
//----------------------------------------------------------------------------------------------------------------------
const static float ZOOM=5.0f;

//----------------------------------------------------------------------------------------------------------------------
GLWindow::GLWindow(const QGLFormat _format, QWidget *_parent ) : QGLWidget( _format, _parent )
{

  // set this widget to have the initial keyboard focus
  this->setFocusPolicy(Qt::ClickFocus);

  m_rotate=false;
  // mouse rotation values set to 0
  m_spinXFace=0.0f;
  m_spinYFace=0.0f;
  //behaviour set variables
  //max velocity
  m_maxVelocity =1;
  //max acceleration
  m_maxAccel = 0.01;
  //cohesion treshold
  m_cohesionTresh=0.1;
  //allignment treshold
  m_alignTresh = 0.1;
  //seperation treshold
  m_seperaTresh=0.1;
  //seek treshold
  m_seekTresh=0;
  //wander treshold
  m_wanderTresh=0.1;
  //neigh distance
  m_neighDist =4;
  //seperation dist
  m_seperationDist=2;
  //wander angle
  m_wanderAngle=1;
  //range for m_target
  m_range=20;
  //refresh frequency
  m_timerFreq=300;
  //default boid number
  m_boidNum=0;
  //bounding box size
  m_bbxSize=50;
  // toggle draw of bounding box
  m_drawBBx=true;
  //rotation toggle
  m_rotToggle = true;
  //scale
  m_radius =2;
  this->resize(_parent->size());

}

//----------------------------------------------------------------------------------------------------------------------
GLWindow::~GLWindow()
{
    ngl::NGLInit *Init = ngl::NGLInit::instance();
    std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
    delete m_light;
    delete m_behave;
    delete m_world;
    delete m_boidLead;
    delete m_text;
    Init->NGLQuit();
}

// This virtual function is called once before the first call to paintGL() or resizeGL(),
//and then once whenever the widget has been assigned a new QGLContext.
// This function should set up any required OpenGL context rendering flags, defining display lists, etc.

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::initializeGL()
{

  // we must call this first before any other GL commands to load and link the
  // gl commands from the lib, if this is not done program will crash
  ngl::NGLInit::instance();

  glClearColor(0.4f, 0.4f, 0.4f, 1.0f);			   // Grey Background
  // enable depth testing for drawing
  glEnable(GL_DEPTH_TEST);
  // enable multisampling for smoother drawing
  glEnable(GL_MULTISAMPLE);
  // now to load the shader and set the values
  // grab an instance of shader manager
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  // we are creating a shader called Phong
  shader->createShaderProgram("Phong");
  // now we are going to create empty shaders for Frag and Vert
  shader->attachShader("PhongVertex",ngl::VERTEX);
  shader->attachShader("PhongFragment",ngl::FRAGMENT);
  // attach the source
  shader->loadShaderSource("PhongVertex","shaders/PhongVertex.glsl");
  shader->loadShaderSource("PhongFragment","shaders/PhongFragment.glsl");
  // compile the shaders
  shader->compileShader("PhongVertex");
  shader->compileShader("PhongFragment");
  // add them to the program
  shader->attachShaderToProgram("Phong","PhongVertex");
  shader->attachShaderToProgram("Phong","PhongFragment");
  // now bind the shader attributes for most NGL primitives we use the following
  // layout attribute 0 is the vertex data (x,y,z)
  shader->bindAttribute("Phong",0,"inVert");
  // attribute 1 is the UV data u,v (if present)
  shader->bindAttribute("Phong",1,"inUV");
  // attribute 2 are the normals x,y,z
  shader->bindAttribute("Phong",2,"inNormal");
  // now we have associated this data we can link the shader
  shader->linkProgramObject("Phong");
  // and make it active ready to load values
  (*shader)["Phong"]->use();
  // the shader will use the currently active material and light0 so set them
  ngl::Material m(ngl::PEWTER);
  // load our material values to the shader into the structure material (see Vertex shader)
  m.loadToShader("material");
  // Now we will create a basic Camera from the graphics library
  // This is a static camera so it only needs to be set once
  // First create Values for the camera position
  ngl::Vec3 from(0,0,m_bbxSize*4);
  ngl::Vec3 to(0,0,0);
  ngl::Vec3 up(0,1,0);
  // now load to our new camera
  m_cam= new ngl::Camera(from,to,up);
  // set the shape using FOV 45 Aspect Ratio based on Width and Height
  // The final two are near and far clipping planes of 0.5 and 10
  m_cam->setShape(50.0f,(float)this->size().width()/(float)this->size().height(),0.05f,350.0f);
  shader->setShaderParam3f("viewerPos",m_cam->getEye().m_x,m_cam->getEye().m_y,m_cam->getEye().m_z);
  // now create our light this is done after the camera so we can pass the
  // transpose of the projection matrix to the light to do correct eye space
  // transformations
  ngl::Mat4 iv=m_cam->getViewMatrix();
  iv.transpose();
  m_light = new ngl::Light(ngl::Vec3(0,-25,0),ngl::Colour(0,1,0.2,1),ngl::Colour(1,1,1,1),ngl::POINTLIGHT );
  m_light->setTransform(iv);
  // load these values to the shader as well
  m_light->loadToShader("light");
  //create text
  m_text = new  ngl::Text(QFont("Arial",18));
  m_text->setScreenSize(this->size().width(),this->size().height());
  //create beahaviour object
  m_behave = new Behaviour();
  //create flock object
  m_flock = new Flock();
  //add boids to boid list
  m_flock->boidFlock(m_boidNum,m_boids,m_radius);
  //create world
  m_world = new World();
  //create walls for world
  ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
  prim->createLineGrid("wall", 1, 1, 1);
  m_world->addNewWall(m_walls,ngl::Vec3(-m_bbxSize,0,0), m_bbxSize*2, ngl::Vec3(1.0, 0.0, 0.0),false);
  m_world->addNewWall(m_walls,ngl::Vec3(m_bbxSize,0,0), m_bbxSize*2, ngl::Vec3(-1.0, 0.0, 0.0),false);
  m_world->addNewWall(m_walls,ngl::Vec3(0,m_bbxSize,0), m_bbxSize*2, ngl::Vec3(0.0, -1.0, 0.0),false);
  m_world->addNewWall(m_walls,ngl::Vec3(0,-m_bbxSize,0), m_bbxSize*2, ngl::Vec3(0.0, 1.0, 0.0),false);
  m_world->addNewWall(m_walls,ngl::Vec3(0,0,m_bbxSize), m_bbxSize*2, ngl::Vec3(0.0, 0.0, -1.0),false);
  m_world->addNewWall(m_walls,ngl::Vec3(0,0,-m_bbxSize), m_bbxSize*2, ngl::Vec3(0.0, 0.0, 1.0),false);
  //build boid VAO
  buildVAO();
  glViewport(0,0,width()*devicePixelRatio(),height()*devicePixelRatio());
  //set timer
  m_timer = 0;
  
  prim->createSphere("sphere", 1.0f, 10);
  
  //timer
  startTimer(60);
}

//----------------------------------------------------------------------------------------------------------------------
//This virtual function is called whenever the widget has been resized.
// The new size is passed in width and height.
void GLWindow::resizeGL( int _w, int _h )
{
  glViewport(0,0,_w,_h);
  //set text and transform it
  m_text->setScreenSize(_w,_h);
  float x,y;
  float mw=1490;
  float mh=900;
  x=1.1-float(mw-_w)/mw;
  y=1.1-float(mh-_h)/mh;
  m_text->setTransform(x,y);
}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::loadMatricesToShader(ngl::Transformation &_transform)
{
  //method to load matrices to shaders
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  ngl::Mat4 MV;
  ngl::Mat4 MVP;
  ngl::Mat3 normalMatrix;
  ngl::Mat4 M;
  M=m_mouseGlobalTX;
  MV=  _transform.getMatrix()*M*m_cam->getViewMatrix();
  MVP= _transform.getMatrix()*M*m_cam->getVPMatrix();
  normalMatrix=MV;
  normalMatrix.inverse();
  shader->setShaderParamFromMat4("MV",MV);
  shader->setShaderParamFromMat4("MVP",MVP);
  shader->setShaderParamFromMat3("normalMatrix",normalMatrix);
  shader->setShaderParamFromMat4("M",M);
}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::buildVAO()
{
  //method to create the boid shape
  //add vertices to array
  ngl::Vec3 verts[]=
  {
    ngl::Vec3(0,0,0.25),
    ngl::Vec3(0.1,0,-0.1),
    ngl::Vec3(-0.1,0,-0.1),
  };
  //push back normals
  std::vector <ngl::Vec3> normals;
  ngl::Vec3 n=ngl::calcNormal(verts[2],verts[1],verts[0]);
  normals.push_back(n);
  normals.push_back(n);
  normals.push_back(n);
  //create vertex array object
  m_vao= ngl::VertexArrayObject::createVOA(GL_TRIANGLES);
  m_vao->bind();
  // in this case we are going to set our data as the vertices above
  m_vao->setData(sizeof(verts),verts[0].m_x);
  // now we set the attribute pointer to be 0 (as this matches vertIn in our shader)
  m_vao->setVertexAttributePointer(0,3,GL_FLOAT,0,0);
  m_vao->setData(sizeof(verts),normals[0].m_x);
  // now we set the attribute pointer to be 2 (as this matches normal in our shader)
  m_vao->setVertexAttributePointer(2,3,GL_FLOAT,0,0);
  m_vao->setNumIndices(sizeof(verts)/sizeof(ngl::Vec3));
  // now unbind
  m_vao->unbind();
}

//----------------------------------------------------------------------------------------------------------------------
//This virtual function is called whenever the widget needs to be painted.
// this is our main drawing routine
void GLWindow::paintGL()
{
  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Rotation based on the mouse position for our global transform
  ngl::Mat4 rotX;
  ngl::Mat4 rotY;
  // create the rotation matrices
  rotX.rotateX(m_spinXFace);
  rotY.rotateY(m_spinYFace);
  // multiply the rotations
  m_mouseGlobalTX=rotY*rotX;
  // add the translations
  m_mouseGlobalTX.m_m[3][0] = m_modelPos.m_x;
  m_mouseGlobalTX.m_m[3][1] = m_modelPos.m_y;
  m_mouseGlobalTX.m_m[3][2] = m_modelPos.m_z;

  // DRAW BOUNDING BOX
  if(m_drawBBx == true)
    {
      BOOST_FOREACH(Wall *w, m_walls)
      {
        {
          //use default shader
          ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
          ngl::ShaderLib *shader=ngl::ShaderLib::instance();
          (*shader)["nglColourShader"]->use();
          //set transforms
          m_wallTransform.setPosition(w->centre);
          m_wallTransform.setScale(w->size, w->size, w->size);
          m_wallTransform.setRotation(m_world->getRotationFromY(ngl::Vec3(w->a,w->b,w->c)));
          //load to shader
          ngl::Mat4 MVP= m_wallTransform.getMatrix()
              *m_mouseGlobalTX* m_cam->getVPMatrix();
          shader->setShaderParamFromMat4("MVP",MVP);
          prim->draw("wall");
        }
      }
    }

  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  (*shader)["Phong"]->use();
  //boid random point update interval
  //std::cout << m_timer << std::endl;
  //std::cout << m_timerFreq << std::endl;
  //std::cout << m_timer/m_timerFreq << std::endl;
  if (m_timer/m_timerFreq >= 1)
    {
      ngl::Random *rng=ngl::Random::instance();
      rng->setSeed();
      m_target=rng->getRandomPoint(m_range,m_range,m_range);
      m_timer = 0;
    }
    //load to shaders
    
    //bind VAO
    m_vao->bind();
    //drawVAO
    m_vao->draw();
    //unbind VAO
    m_vao->unbind();
  for(unsigned int i =0 ; i<m_boids.size(); i++)
    {
      //get position to behaviour class
      m_behave->getPos(m_boids[i]->getPosition());
      //random point for wander behavior
      ngl::Random *rng=ngl::Random::instance();
      ngl::Vec3 rand = rng->getRandomPoint();
      m_wanderAngle += rand.m_x;

      //COHESION
      m_behave->Cohesion(i,m_boids, m_nearBoids,m_maxVelocity,m_maxAccel,m_neighDist);
      //SEPERATION
      m_behave->Seperation(i,m_boids,m_nearBoids,m_maxVelocity,m_maxAccel,m_seperationDist);
      //ALLIGNMENT
      m_behave->Allignment(i,m_boids,m_maxAccel,m_maxVelocity,m_nearBoids,m_neighDist);
      //WANDER
      m_behave->Wander(m_boids[i]->getVelocity(), m_nearBoids, m_maxAccel, m_wanderAngle);
      //SEEK
      m_behave->Seek(m_target,m_boids[i]->getVelocity(),m_maxVelocity,m_maxAccel,m_boids[i]->getPosition());
      //FINAL BEHAVIOUR VELOCITY
      m_behave->finalBehaviourVelocity(m_cohesionTresh, m_alignTresh, m_seperaTresh, m_seekTresh, m_wanderTresh);

      //get behaviour velocity
      m_finalVel=m_behave->getFinalBehaviourVelocity();
      //update boid's velocity
      m_boids[i]->updateVelocity(m_finalVel, m_maxVelocity, m_maxAccel);
      //update boid's position
      m_boids[i]->updatePos();
      //update rotation
      m_boids[i]->updateRot();
      //check wall collision
      m_world->collisionWithWalls(m_walls,m_boids[i], m_maxVelocity, m_maxAccel);
      //get translation matrix
      ngl::Mat4 rot;
      if(m_rotToggle == true)
        {
          rot = m_boids[i]->getRotMat();
        }
      else
        {
          rot.identity();
        }
      
      ngl::Mat4 scale;
      scale.scale(m_radius*2,m_radius*2,m_radius*2);
      
      ngl::Mat4 translate;
      ngl::Vec3 t(m_boids[i]->getPosition());
      translate.translate(t.m_x, t.m_y, t.m_z);
          
      m_boidTransform.setMatrix(scale*rot*translate);
      
      //load to shaders
      loadMatricesToShader(m_boidTransform);
      m_boidTransform.reset();
      //bind VAO
      m_vao->bind();
      //drawVAO
      m_vao->draw();
      //unbind VAO
      m_vao->unbind();
    }
  ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
  ngl::Transformation targetTrans;
  targetTrans.setPosition(m_target);
  loadMatricesToShader(targetTrans);
  m_vao->bind();
  prim->draw("sphere");
  m_vao->unbind();
  //write text
  m_text->setColour(ngl::Colour(1,1,1));
  m_text->renderText(10,16," B key to add a single boid");
  //write boid counter
  QString text=QString("Boid amount %1 ").arg(m_boids.size());
  m_text->renderText(900,18,text );
  //update timer
  m_timer+=1.0f;
}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::timerEvent(QTimerEvent *_event)
{
  //methdod to update context
  updateGL();
}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::mouseMoveEvent ( QMouseEvent * _event )
{
  // note the method buttons() is the button state when event was called
  // this is different from button() which is used to check which button was
  // pressed when the mousePress/Release event is generated
  if(m_rotate && _event->buttons() == Qt::LeftButton)
    {
      int diffx=_event->x()-m_origX;
      int diffy=_event->y()-m_origY;
      m_spinXFace += (float) 0.5f * diffy;
      m_spinYFace += (float) 0.5f * diffx;
      m_origX = _event->x();
      m_origY = _event->y();
    }

  // right mouse translate code
  else if(m_translate && _event->buttons() == Qt::RightButton)
    {
      int diffX = (int)(_event->x() - m_origXPos);
      int diffY = (int)(_event->y() - m_origYPos);
      m_origXPos=_event->x();
      m_origYPos=_event->y();
      m_modelPos.m_x += INCREMENT * diffX;
      m_modelPos.m_y -= INCREMENT * diffY;

    }
}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::mousePressEvent ( QMouseEvent * _event)
{
  // this method is called when the mouse button is pressed in this case we
  // store the value where the maouse was clicked (x,y) and set the Rotate flag to true
  if(_event->button() == Qt::LeftButton)
    {
      m_origX = _event->x();
      m_origY = _event->y();
      m_rotate =true;
    }
  // right mouse translate mode
  else if(_event->button() == Qt::RightButton)
    {
      m_origXPos = _event->x();
      m_origYPos = _event->y();
      m_translate=true;
    }

}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::mouseReleaseEvent ( QMouseEvent * _event )
{
  // this event is called when the mouse button is released
  // we then set Rotate to false
  if (_event->button() == Qt::LeftButton)
    {
      m_rotate=false;
    }
  // right mouse translate mode
  if (_event->button() == Qt::RightButton)
    {
      m_translate=false;
    }

}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::wheelEvent(QWheelEvent *_event)
{

  // check the diff of the wheel position (0 means no change)
  if(_event->delta() > 0)
    {
      m_modelPos.m_z+=ZOOM;
    }
  else if(_event->delta() <0 )
    {
      m_modelPos.m_z-=ZOOM;
    }
}

//----------------------------------------------------------------------------------------------------------------------
void GLWindow::keyPressEvent(QKeyEvent *_event)
{
  // this method is called every time the main window recives a key event.
  // we then switch on the key value and set the camera in the GLWindow

  switch (_event->key())
    {
    // escape key to quit
    case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;
      //add boids
    case Qt::Key_B : m_flock->boidFlock(1, m_boids, m_radius); break;
    default : break;
    }
  // finally update the GLWindow and re-draw
  //if (isExposed())
  updateGL();

}
void GLWindow::changeRot(bool _bool)
{
  //GUI method to toggle draw of bounding box on/off
  m_rotToggle=_bool;
  updateGL();
}
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::changeBoidRadius(double _number)
{
  //GUI method to update boid number
  m_radius=_number;
  updateGL();
}
//----------------------------------------------------------------------------------------------------------------------
void GLWindow::changeBoidNum(int _number)
{
  //GUI method to update boid number
  m_boidNum = _number;
  m_flock->flockClear(m_boids);
  m_flock->boidFlock(_number,m_boids,m_radius);
  updateGL();
}
void GLWindow::changeMAXVelocity(double _number)
{
  //GUI method to update max velocity
  m_maxVelocity=_number;
  updateGL();
}
void GLWindow::changeMAXAccel(double _number)
{
  //GUI method to update max acceleration
  m_maxAccel=_number;
  updateGL();
}
void GLWindow::changeTimerFreq(int _number)
{
  //GUI method to update timer frequency
  m_timerFreq=_number;
  updateGL();
}
void GLWindow::changeRange(double _number)
{
  //GUI method to update m_traget range
  m_range=_number;
  updateGL();
}
void GLWindow::changeDrawBox(bool _bool)
{
  //GUI method to toggle draw of bounding box on/off
  m_drawBBx=_bool;
  updateGL();
}
void GLWindow::changeCohesionTresh(double _number)
{
  //GUI method to update cohesion treshold
  m_cohesionTresh=_number;
  updateGL();
}
void GLWindow::changeAllignTresh(double _number)
{
  //GUI method to update allignemnt treshold
  m_alignTresh = _number;
  updateGL();
}
void GLWindow::changeSeperatTresh(double _number)
{
  //GUI method to update seperation treshold
  m_seperaTresh=_number;
  updateGL();
}
void GLWindow::changeSeperatDist(double _number)
{
  //GUI method to update seperation distance
  m_seperationDist= _number;
  updateGL();
}
void GLWindow::changeSeekTresh(double _number)
{
  //GUI method to update seek treshold
  m_seekTresh=_number;
  updateGL();
}
void GLWindow::changeCohesionDist(double _number)
{
  //GUI method to update cohesion distance
  m_neighDist = _number;
  updateGL();
}
void GLWindow::changeWanderTresh(double _number)
{
  //GUI method to update wander treshold
  m_wanderTresh=_number;
  updateGL();
}
void GLWindow::writeFile()
{
  //GUI method to write variables to text file "UserVariables.txt"
  std::ofstream outFile;
  outFile.open("Variable_text_files/UserVariables.txt"); //destination
  if(outFile.fail())
    {
      std::cerr<<"Error Writing file"<<std::endl;
      std::exit(1);
    }
  outFile<<"BoidNumber"<<std::endl<<m_boidNum<<std::endl
             <<"Scale"<<std::endl<<m_radius<<std::endl
             <<"Rotations"<<std::endl<<m_rotToggle<<std::endl
            <<"MaxVelocity"<<std::endl<<m_maxVelocity<<std::endl
            <<"MaxAcceleration"<<std::endl<<m_maxAccel<<std::endl
            <<"TimerFrequency"<<std::endl<<m_timerFreq<<std::endl
            <<"Range"<<std::endl<<m_range<<std::endl
            <<"DrawBBx"<<std::endl<<m_drawBBx<<std::endl
            <<"Cohesion"<<std::endl<<m_cohesionTresh<<std::endl
            <<"CohesionDistance"<<std::endl<<m_neighDist<<std::endl
            <<"Seperation"<<std::endl<<m_seperaTresh<<std::endl
            <<"SeperationDistance"<<std::endl<<m_seperationDist<<std::endl
           <<"Allignment"<<std::endl<<m_alignTresh<<std::endl
           <<"Wander"<<std::endl<<m_wanderTresh<<std::endl
           <<"Seek"<<std::endl<<m_seekTresh<<std::endl;
  outFile.close();
}

