#ifndef GL_WINDOW_H__
#define GL_WINDOW_H__

#include <ngl/Transformation.h>
#include <ngl/Vec3.h>
#include <QEvent>
#include <QResizeEvent>
#include <QGLWidget>
#include <ngl/Text.h>
#include <ngl/Camera.h>
#include <ngl/Colour.h>
#include <ngl/Light.h>
#include <ngl/Text.h>
#include <ngl/Transformation.h>
#include <boid.h>
#include <behaviour.h>
#include <ngl/BBox.h>
#include "flock.h"
#include "world.h"
#include <ngl/Text.h>

/// @file GLWindow.h
/// @brief a basic Qt GL window class for ngl demos
/// @author original author Jonathan Macey, adapted by Eligijus Titas
/// @version 1.1
/// @date 15/05/15
/// Revision History :
/// Initial Version 10/10/10 (Binary day ;-0 )
/// @class GLWindow
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file
class GLWindow : public QGLWidget
{
  Q_OBJECT       // must include this if you use Qt signals/slots

public slots:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief rot toggle on/off
  //----------------------------------------------------------------------------------------------------------------------
  void changeRot(bool _bool);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief scale boids
  //----------------------------------------------------------------------------------------------------------------------
  void changeBoidRadius(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the boid number from the GUI
  /// @param [in] _number amount to change the value
  //----------------------------------------------------------------------------------------------------------------------
  void  changeBoidNum(int _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the boids' maximum velocity from the GUI
  /// @param [in] _number maximum amount of the boids' velocity
  //----------------------------------------------------------------------------------------------------------------------
  void changeMAXVelocity(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the boids' maximum acceleration from the GUI
  /// @param [in] _number maximum amount ot change
  //----------------------------------------------------------------------------------------------------------------------
  void changeMAXAccel(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the frequence of the update of the target for seek behaviour from the GUI
  /// @param [in] _number amount to change the frequency of the update
  //----------------------------------------------------------------------------------------------------------------------
  void changeTimerFreq(int _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the range for the seek target from the GUI
  /// @param [in] _number the maximum radius of the target's position
  //----------------------------------------------------------------------------------------------------------------------
  void changeRange(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change if the bounding box should be drawn from the GUI
  /// @param [in] _bool to toggle drawing of bounding box
  //----------------------------------------------------------------------------------------------------------------------
  void changeDrawBox(bool _bool);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the Cohesion Treshold from the GUI
  /// @param [in] _number amount to change the treshold of Cohesion
  //----------------------------------------------------------------------------------------------------------------------
  void changeCohesionTresh(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the Allignment Treshold from the GUI
  /// @param [in] _number amount to change the value
  //----------------------------------------------------------------------------------------------------------------------
  void changeAllignTresh(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change Seperation Treshold from the GUI
  /// @param [in] _number amount to change the Seperation Treshold value
  //----------------------------------------------------------------------------------------------------------------------
  void changeSeperatTresh(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change Seperate Distance from the GUI
  /// @param [in] _number amount to change the value seperation distance
  //----------------------------------------------------------------------------------------------------------------------
  void changeSeperatDist(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the Seek Treshold from the GUI
  /// @param [in] _number amount to change the value of Seek Treshold
  //----------------------------------------------------------------------------------------------------------------------
  void changeSeekTresh(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the cohesion distance from the GUI
  /// @param [in] _number amount to change the value
  //----------------------------------------------------------------------------------------------------------------------
  void changeCohesionDist(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the Wander behaviour treshold number from the GUI
  /// @param [in] _number amount to change the Wander behaviour treshold
  //----------------------------------------------------------------------------------------------------------------------
  void changeWanderTresh(double _number);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief write a .txt file of all the variables in the GUI
  //----------------------------------------------------------------------------------------------------------------------
  void writeFile();
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ctor for our NGL drawing class
  /// @param [in] parent the parent window to the class
  //----------------------------------------------------------------------------------------------------------------------
  GLWindow(const QGLFormat _format,QWidget *_parent );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief dtor must close down ngl and release OpenGL resources
  //----------------------------------------------------------------------------------------------------------------------
  ~GLWindow();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the initialize class is called once when the window is created and we have a valid GL context
  /// use this to setup any default GL stuff
  //----------------------------------------------------------------------------------------------------------------------
  void initializeGL();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this is called everytime we want to draw the scene
  //----------------------------------------------------------------------------------------------------------------------
  void paintGL();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this is called everytime we want to resize the scene
  /// @param [in] _w the width of the openGL context
  /// @param [in] _h the height of the openGL context
  //----------------------------------------------------------------------------------------------------------------------
  void resizeGL( int _w, int _h );

private:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the x rotation mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_spinXFace;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the y rotation mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_spinYFace;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief flag to indicate if the mouse button is pressed when dragging
  //----------------------------------------------------------------------------------------------------------------------
  bool m_rotate;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief flag to indicate if the Right mouse button is pressed when dragging
  //----------------------------------------------------------------------------------------------------------------------
  bool m_translate;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous x mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_origX;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous y mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_origY;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous x mouse value for Position changes
  //----------------------------------------------------------------------------------------------------------------------
  int m_origXPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous y mouse value for Position changes
  //----------------------------------------------------------------------------------------------------------------------
  int m_origYPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the global mouse transforms
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Mat4 m_mouseGlobalTX;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Our Camera
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Camera *m_cam;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the model position for mouse movement
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_modelPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief a simple light use to illuminate the screen
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Light *m_light;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to load transform matrices to the shader
  /// @param [in] _transform to load in a tranform variable
  //----------------------------------------------------------------------------------------------------------------------
  void loadMatricesToShader(ngl::Transformation &_transform);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Qt Event called when the window is re-sized
  /// @param [in] _event the Qt event to query for size etc
  //----------------------------------------------------------------------------------------------------------------------
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Qt Event called when a key is pressed
  /// @param [in] _event the Qt event to query for size etc
  //----------------------------------------------------------------------------------------------------------------------
  void keyPressEvent(QKeyEvent *_event);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called every time a mouse is moved
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void mouseMoveEvent (QMouseEvent * _event );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse button is pressed
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void mousePressEvent ( QMouseEvent *_event);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse button is released
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void mouseReleaseEvent ( QMouseEvent *_event );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime the mouse wheel is moved
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void wheelEvent( QWheelEvent *_event);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called everytime to update the OpenGL context
  /// inherited from QObject and overridden here.
  /// @param _event the Qt Event structure
  //----------------------------------------------------------------------------------------------------------------------
  void timerEvent(QTimerEvent *_event);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief this method is called to build VAO for a boid
  //----------------------------------------------------------------------------------------------------------------------
  void buildVAO();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief on screen text for information of the scene
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Text *m_text;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief arrayObject to hold the vertices of the VAO boid
  //----------------------------------------------------------------------------------------------------------------------
  ngl::VertexArrayObject *m_vao;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the seek target position
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_target;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief object for Behaviours
  //----------------------------------------------------------------------------------------------------------------------
  Behaviour *m_behave;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief transformation variable to laod into loadMatricestoShader() method
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Transformation m_transform;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief keep track of the timer
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Real m_timer;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief storing the Boid object
  //----------------------------------------------------------------------------------------------------------------------
  Boid *m_boid;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store all of the boids
  //----------------------------------------------------------------------------------------------------------------------
  std::vector<Boid*> m_boids;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store all of the nearby boids around an object/boid
  //----------------------------------------------------------------------------------------------------------------------
  std::vector<Boid*> m_nearBoids;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief set maximum velocity for boids
  //----------------------------------------------------------------------------------------------------------------------
  double m_maxVelocity;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief set maximum acceleration for boids
  //----------------------------------------------------------------------------------------------------------------------
  double m_maxAccel;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Ter boid object
  //----------------------------------------------------------------------------------------------------------------------
  Boid *m_boidLead;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief slow down range for the seek behaviour
  //----------------------------------------------------------------------------------------------------------------------
  float m_slowRad;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief maximum range in x, y, z for the m_target's position
  //----------------------------------------------------------------------------------------------------------------------
  float m_range;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief frequency of the m_target position update
  //----------------------------------------------------------------------------------------------------------------------
  int m_timerFreq;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief amount of boids to create
  //----------------------------------------------------------------------------------------------------------------------
  int m_boidNum;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief bounding box size
  //----------------------------------------------------------------------------------------------------------------------
  float m_bbxSize;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief leader boid position
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_boidLeadPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief leader boid velocity
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_boidLeadVelocity;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief toggle to turn on/off drawing of the bounding box
  //----------------------------------------------------------------------------------------------------------------------
  bool m_drawBBx;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief check collision with walls
  /// @param _boid takes a boid to check for collisions
  //----------------------------------------------------------------------------------------------------------------------
  void collisionWithWalls(Boid *_boid);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief vector for the bounding box walls
  //----------------------------------------------------------------------------------------------------------------------
  std::vector <Wall *> m_walls;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief final behaviour velocity
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_finalVel;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief boid's position
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_boidPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to add a new wall to draw
  /// @param _point central point of the wall
  /// @param _size size of the wall
  /// @param _normal the normal direction of the wall
  /// @param _draw bool value to draw the walls
  //----------------------------------------------------------------------------------------------------------------------
  void addNewWall(ngl::Vec3 _point, float _size, ngl::Vec3 _normal, bool _draw);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get rotation from Y
  /// @param _vec get rotation from a vector
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 getRotationFromY(ngl::Vec3 _vec) const;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief object to hold the flock
  //----------------------------------------------------------------------------------------------------------------------
  Flock *m_flock;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief object to hold the world
  //----------------------------------------------------------------------------------------------------------------------
  World *m_world;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief transformation for the walls
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Transformation m_wallTransform;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief transformation for the boids
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Transformation m_boidTransform;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief transformation for the boid leader
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Transformation m_boidLeadTransform;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief maximum lead velocity
  //----------------------------------------------------------------------------------------------------------------------
  double m_maxLeadVelocity;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief maximum lead acceleration
  //----------------------------------------------------------------------------------------------------------------------
  double m_maxLeadAccel;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief cohesion treshold
  //----------------------------------------------------------------------------------------------------------------------
  double m_cohesionTresh;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief allignment treshold
  //----------------------------------------------------------------------------------------------------------------------
  double m_alignTresh;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief seperation treshold
  //----------------------------------------------------------------------------------------------------------------------
  double m_seperaTresh;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief seeking treshold
  //----------------------------------------------------------------------------------------------------------------------
  double m_seekTresh;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief wander treshold
  //----------------------------------------------------------------------------------------------------------------------
  double m_wanderTresh;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief max seperation distance
  //----------------------------------------------------------------------------------------------------------------------
  double m_seperationDist;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief max neighbour distance
  //----------------------------------------------------------------------------------------------------------------------
  double m_neighDist;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief wander angle
  //----------------------------------------------------------------------------------------------------------------------
  double m_wanderAngle;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief rotations on/off
  //----------------------------------------------------------------------------------------------------------------------
  bool m_rotToggle;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief scale boids
  //----------------------------------------------------------------------------------------------------------------------
  double m_radius;
};



#endif
