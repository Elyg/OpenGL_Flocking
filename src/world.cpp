#include "world.h"
#include <ngl/NGLStream.h>


World::World()//ctor
{

}

//----------------------------------------------------------------------------------------------------------------------
void World::collisionWithWalls(std::vector <Wall*> &_walls,Boid *_boid, float _maxVelocity, float _maxAccel )
{
  //setting temporary values
  ngl::Vec3 oldP, oldV, newP, newV, wallNormal;
  float radius, dist, bounce;
  oldP = _boid->getPosition();
  oldV = _boid->getVelocity();
  radius = _boid->getRadius();
  bounce = 0.5;
  //iteratre to check if boid hits wall

  BOOST_FOREACH(Wall *w, _walls)
  {
    wallNormal.m_x = w->a; wallNormal.m_y = w->b; wallNormal.m_z = w->c;
    dist = oldP.m_x * w->a + oldP.m_y * w->b + oldP.m_z * w->c + w->d - radius;
    if(dist < 0) // if hit wall bounce back
      {
        newV = bounce*(-oldV.dot(wallNormal)*wallNormal+(oldV-oldV.dot(wallNormal)*wallNormal));
        newP = oldP - dist*wallNormal;
        //set new velocity and position
        _boid->setVelocity(newV, _maxVelocity, _maxAccel);
        _boid->setPosition(newP);
      }

  }

}

//----------------------------------------------------------------------------------------------------------------------
void World::addNewWall(std::vector <Wall *> &_walls,ngl::Vec3 _point, float _size, ngl::Vec3 _normal, bool _draw)
{
  //method for adding new walls
  Wall *newWall = new Wall;
  _normal.normalize();
  newWall->centre = _point;
  newWall->size = _size;
  newWall->a = _normal.m_x;
  newWall->b = _normal.m_y;
  newWall->c = _normal.m_z;
  newWall->d = -(newWall->a * _point.m_x + newWall->b * _point.m_y + newWall->c * _point.m_z);
  newWall->draw = _draw;
  _walls.push_back(newWall);
}

//----------------------------------------------------------------------------------------------------------------------
ngl::Vec3 World::getRotationFromY(ngl::Vec3 _vec) const
{
  //get rotation for bounding box
  ngl::Vec3 rot;
  rot.m_z = 0.0;
  if(fabs(_vec.m_y)< 0.0001)
    {
      if (_vec.m_z>= 0.0)
        rot.m_x = -90;
      else
        rot.m_x = 90;
    }
  else
    rot.m_x = atan(_vec.m_z/_vec.m_y);
  if(fabs(_vec.m_y) + fabs(_vec.m_z) < 0.0001)
    {
      if(_vec.m_x > 0)
        rot.m_y = -90;
      else
        rot.m_y = 90;
    }
  else
    rot.m_z = atan(_vec.m_x/sqrt(_vec.m_y*_vec.m_y + _vec.m_z*_vec.m_z));

  return rot;
}


