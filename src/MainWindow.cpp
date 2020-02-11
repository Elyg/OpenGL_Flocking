#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFile>
#include <QTextStream>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), m_ui(new Ui::MainWindow)
{
  m_ui->setupUi(this);
  // create an openGL format and pass to the new GLWidget
  QGLFormat format;
  format.setSamples(4);
  format.setVersion(4,1);
  format.setProfile( QGLFormat::CoreProfile);
  m_gl=new  GLWindow(format,this);
  //grid layout for openGL
  m_ui->s_GLWindowGridLayout->addWidget(m_gl,0,0,3,1);
  //connect boid number uodate method
  connect(m_ui->BoidNumb,SIGNAL(valueChanged(int)),m_gl,SLOT(changeBoidNum(int)));
  //connect boid max velocity update method
  connect(m_ui->MaxVelocityVal,SIGNAL(valueChanged(double)),m_gl,SLOT(changeMAXVelocity(double)));
  //connect boid max acceleration update method
  connect(m_ui->MaxAccelVal,SIGNAL(valueChanged(double)),m_gl,SLOT(changeMAXAccel(double)));
  // connect boid time update method
  connect(m_ui->timerVal,SIGNAL(valueChanged(int)),m_gl,SLOT(changeTimerFreq(int)));
  //connect boid target value update method
  connect(m_ui->targetVal,SIGNAL(valueChanged(double)),m_gl,SLOT(changeRange(double)));
  //connect boid draw bbx toggle update method
  connect(m_ui->Drawbox,SIGNAL(toggled(bool)),m_gl,SLOT(changeDrawBox(bool)));
  //connect boid cohesion treshold update method
  connect(m_ui->CohesionVal,SIGNAL(valueChanged(double)),m_gl,SLOT(changeCohesionTresh(double)));
  //connect boid seperation treshold update method
  connect(m_ui->SeperationVal,SIGNAL(valueChanged(double)),m_gl,SLOT(changeSeperatTresh(double)));
  //connect boid seperation distance update method
  connect(m_ui->SepDist,SIGNAL(valueChanged(double)),m_gl,SLOT(changeSeperatDist(double)));
  //connect boid allignment treshold update method
  connect(m_ui->AllignmentVal,SIGNAL(valueChanged(double)),m_gl,SLOT(changeAllignTresh(double)));
  //connect boid seek treshold update method
  connect(m_ui->SeekVal,SIGNAL(valueChanged(double)),m_gl,SLOT(changeSeekTresh(double)));
  //connect boid wander treshold update method
  connect(m_ui->wanderTrash,SIGNAL(valueChanged(double)),m_gl,SLOT(changeWanderTresh(double)));
  //connect boid cohesion distance update method
  connect(m_ui->CohDist,SIGNAL(valueChanged(double)),m_gl,SLOT(changeCohesionDist(double)));
  //connect write to file button update method
  connect(m_ui->writeButton,SIGNAL(clicked()),m_gl,SLOT(writeFile()));

  //connect scale method
  connect(m_ui->scaleBoid,SIGNAL(valueChanged(double)),m_gl,SLOT(changeBoidRadius(double)));
  //connect rot toggle method
  connect(m_ui->rotToggle,SIGNAL(toggled(bool)),m_gl,SLOT(changeRot(bool)));

}

//----------------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow() //dtor
{
  delete m_ui;
}

//----------------------------------------------------------------------------------------------------------------------
void MainWindow::on_readTest_clicked()
{
  //method to read Defaults.txt config file
  QFile inFile("Variable_text_files/Defaults.txt"); //destination
  if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      std::cerr<<"Error Reading file"<<std::endl;
      std::exit(1);
    }
  //read all variables as string lines and update GUI
  QTextStream in(&inFile);
  in.readLine();
  m_ui->BoidNumb->setValue(in.readLine().toInt());
  in.readLine();
  m_ui->scaleBoid->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->rotToggle->setChecked(in.readLine().toInt());
  in.readLine();
  m_ui->MaxVelocityVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->MaxAccelVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->timerVal->setValue(in.readLine().toInt());
  in.readLine();
  m_ui->targetVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->Drawbox->setChecked(in.readLine().toInt());
  in.readLine();
  m_ui->CohesionVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->CohDist->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->SeperationVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->SepDist->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->AllignmentVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->wanderTrash->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->SeekVal->setValue(in.readLine().toDouble());
  //close file
  inFile.close();
}

//----------------------------------------------------------------------------------------------------------------------
void MainWindow::on_readButton_clicked()
{
  //method to read user saved prefrences
  QFile inFile("Variable_text_files/UserVariables.txt");  //destination
  if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
      std::cerr<<"Error Reading file"<<std::endl;
      std::exit(1);
    }
  //read the prefrence file and update GUI
  QTextStream in(&inFile);
  in.readLine();
  m_ui->BoidNumb->setValue(in.readLine().toInt());
  in.readLine();
  m_ui->scaleBoid->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->rotToggle->setChecked(in.readLine().toInt());
  in.readLine();
  m_ui->MaxVelocityVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->MaxAccelVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->timerVal->setValue(in.readLine().toInt());
  in.readLine();
  m_ui->targetVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->Drawbox->setChecked(in.readLine().toInt());
  in.readLine();
  m_ui->CohesionVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->CohDist->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->SeperationVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->SepDist->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->AllignmentVal->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->wanderTrash->setValue(in.readLine().toDouble());
  in.readLine();
  m_ui->SeekVal->setValue(in.readLine().toDouble());
  //close file
  inFile.close();
}

