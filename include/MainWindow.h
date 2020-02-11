#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GLWindow.h"

/// @file MainWindow.h
/// @brief a class to create the world
/// @author original author Jonathan Macey, adapted by Eligijus Titas
/// @version 1.0
/// @date 15/05/15
/// @class MainWindow
/// @brief main class to create the world object

//----------------------------------------------------------------------------------------------------------------------
/// @brief setting namespace for the gui
//----------------------------------------------------------------------------------------------------------------------
namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ctor for the MainWindow object
  //----------------------------------------------------------------------------------------------------------------------
  explicit MainWindow(QWidget *parent = 0);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief dtor for the MainWindow object
  //----------------------------------------------------------------------------------------------------------------------
  ~MainWindow();
private slots:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to read user's file
  //----------------------------------------------------------------------------------------------------------------------
  void on_readTest_clicked();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to read default paramt file
  //----------------------------------------------------------------------------------------------------------------------
  void on_readButton_clicked();
private:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief variable to store gui
  //----------------------------------------------------------------------------------------------------------------------
  Ui::MainWindow *m_ui;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief variable for the opengl widget
  //----------------------------------------------------------------------------------------------------------------------
  GLWindow *m_gl;
};
#endif // MAINWINDOW_H
