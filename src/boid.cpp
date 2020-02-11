#include "boid.h"
#include <ngl/NGLStream.h>
#include <ngl/Random.h>
#include <ngl/ShaderLib.h>
#include <ngl/Transformation.h>
#include <ngl/VAOPrimitives.h>
#include <cmath>


//----------------------------------------------------------------------------------------------------------------------
Boid::Boid(const Boid &b)
{
  //create copy function
  m_pos = b.getPosition();
  m_velocity = b.getVelocity();
  m_lastPos = b.getPosition();
  m_desiredVelocity = b.getVelocity();
  m_rot = b.getRot();
  m_radius = b.getRadius();
}

//----------------------------------------------------------------------------------------------------------------------
Boid::Boid(ngl::Vec3 _pos, ngl::Vec3 _dir, double _radius)
{
  //initialize the overloaded ctor values
  m_pos = _pos;
  m_velocity = _dir;
  m_radius=_radius;
}

//----------------------------------------------------------------------------------------------------------------------
void Boid::updateVelocity(ngl::Vec3 _dir, double _maxVelocity, double _maxAccel)
{
  //update the velocity
  //clamp by max acceleration
  _dir.clamp(_maxAccel);
  //divide by mass
  _dir= _dir / 2;
  //add acceleration to the velocity vector
  m_velocity+=_dir;
  //clamp by max velocity
  m_velocity.clamp(_maxVelocity);
}

//----------------------------------------------------------------------------------------------------------------------
void Boid::setVelocity(ngl::Vec3 _vel, double _maxVelocity, double _maxAccel)
{
  //set velocity
  m_velocity=_vel;
  //clamp
  m_velocity.clamp(_maxVelocity);
}

//----------------------------------------------------------------------------------------------------------------------
void Boid::updatePos()
{
  //update position method
  // store previous postion
  m_lastPos = m_pos;
  //update position by the velocity
  m_pos+=m_velocity;
}

//----------------------------------------------------------------------------------------------------------------------
void Boid::setPosition(ngl::Vec3 _pos)
{
  //store last position
  m_lastPos = m_pos;
  //update position by given value
  m_pos=_pos;
}

//----------------------------------------------------------------------------------------------------------------------
void Boid::updateRot()
{
  //method for rotations - does not work properly
  //create temp value
  ngl::Vec3 targetDir = m_pos-m_lastPos;
  targetDir.normalize();
  ngl::Vec3 up(0,1,0);
  targetDir.normalize();
  
  ngl::Vec3 x = targetDir;
  x.cross(targetDir, up);
  x.normalize();
  
  up.cross(targetDir, x);
  up.normalize();
  
  m_rotMat.identity();
  
  m_rotMat.m_00 = x.m_x;
  m_rotMat.m_01 = x.m_y;
  m_rotMat.m_02 = x.m_z;
  
  m_rotMat.m_10 = up.m_x;
  m_rotMat.m_11 = up.m_y;
  m_rotMat.m_12 = up.m_z;
  
  m_rotMat.m_20 = targetDir.m_x;
  m_rotMat.m_21 = targetDir.m_y;
  m_rotMat.m_22 = targetDir.m_z;
  
}

//----------------------------------------------------------------------------------------------------------------------
void Boid::setRadius(double _radius)
{
  //set Radius
  m_radius=_radius;
}























