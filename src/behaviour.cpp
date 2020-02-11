#include "behaviour.h"
#include "boid.h"
#include <vector>
#include <ngl/Vec3.h>
#include <ngl/NGLStream.h>
#include <ngl/Random.h>
#include <boost/foreach.hpp>

Behaviour::Behaviour()
{
  //set the default values
  m_cohesion =0;
  m_allignment =0;
  m_behaveVelocity=0;
  m_leadBehindDist=1;
}
//----------------------------------------------------------------------------------------------------------------------
void Behaviour::getPos(ngl::Vec3 _pos)
{
  //get position of the boid
  m_pos = _pos;
}
//----------------------------------------------------------------------------------------------------------------------
Behaviour::~Behaviour()
{
  //destructor
}

//----------------------------------------------------------------------------------------------------------------------
ngl::Vec3 Behaviour::setAngle(ngl::Vec3 _vec, double _angle)
{
  float length = _vec.length();
  _vec.m_x=cos(_angle) * length;
  _vec.m_y=sin(_angle) * length;
  //_vec.m_z=cos(_angle) * length;
  return _vec;
}
//----------------------------------------------------------------------------------------------------------------------
void Behaviour::Wander(ngl::Vec3 const _vel, std::vector<Boid*> _nearList, float _maxAccel, double _wanderAngle)
{
  if(m_nearBoids==0) //check if there are any near boids to activate wandering
    {
      //set the variables
      float circleDist =2;
      float circleRad= 5;
      m_wander = 0;
      //move the circle
      ngl::Vec3 circleCenter = _vel;
      circleCenter.normalize();
      circleCenter*=circleDist;
      //generate random point for displacement of vector
      ngl::Random *rng=ngl::Random::instance();
      ngl::Vec3 dispalcement = rng->getRandomNormalizedVec3();
      dispalcement*=circleRad;
      //set angle
      dispalcement=setAngle(dispalcement,_wanderAngle);
      //add to the wander behaviour, clamp, normalize
      m_wander+=dispalcement;
      m_wander.clamp(_maxAccel);
      m_wander.normalize();
    }

}
//----------------------------------------------------------------------------------------------------------------------
void Behaviour::Seek(ngl::Vec3 const &_target, const ngl::Vec3 &_currentVel, double _maxVel,double _maxAccel, ngl::Vec3 const &_pos)
{
  //reset variables
  m_seeking = 0;
  m_desiredVelocity =0;

  //get desired velocity
  m_desiredVelocity= _target - _pos;
  //add to the seek velocity, clam, normalize
  m_desiredVelocity *=_maxVel;
  m_seeking = m_desiredVelocity - _currentVel;
  m_seeking.clamp(_maxAccel);
  m_seeking.normalize();
// negate and it will be Fleeing behaviour

}

//----------------------------------------------------------------------------------------------------------------------
void Behaviour::Cohesion(unsigned int boidID, std::vector<Boid *> &_boidList, std::vector<Boid *> &_nearList, double _maxVelocity, double _maxAccel, double _neighDist)
{
  //reset values
  m_cohesion =0;
  m_nearBoids =0;
  m_distance=0;

  //check current boid and compare it others
  for (unsigned int i=0; i<_boidList.size();i++)
    {
      m_distance = _boidList[boidID]->getPosition()- _boidList[i]->getPosition();
      if(m_distance.length() >0 && m_distance.length() < _neighDist) // check if in neighbourhood
        {
          // get position
          m_cohesion+=_boidList[i]->getPosition();
          //update counter
          m_nearBoids++;
        }
    }
  if (m_nearBoids>0)
    {
       //devide, subtract current boid's position and clamp
      m_cohesion=m_cohesion/m_nearBoids;
      m_cohesion -= _boidList[boidID]->getPosition();
      m_cohesion.clamp(_maxAccel);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Behaviour::Seperation(unsigned int boidID, std::vector<Boid *> &_boidList, std::vector<Boid *> &_nearList, double _maxVelocity, double _maxAccel, double _seperationDist)
{
  //reset values
  m_seperation =0;
  m_nearBoids =0;
  m_distance=0;

  //check current boid and compare it others
  for (unsigned int i=0; i<_boidList.size();i++)
    {
      m_distance = _boidList[boidID]->getPosition()-_boidList[i]->getPosition();
      if(m_distance.length() >0 && m_distance.length() <= _seperationDist)// check if in neighbourhood
        {
          {
            //add to the seperation
            m_seperation+=m_distance;
            //update counter
            m_nearBoids++;
          }
        }
    }
  if(m_nearBoids>0)
    {
      //devide by boid count and clamp
      m_seperation=m_seperation/m_nearBoids;
      m_allignment.clamp(_maxAccel);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Behaviour::Allignment(unsigned int boidID ,std::vector<Boid *> &_boidList, double _maxAccel,double _maxVelocity, std::vector<Boid *> &_nearList, double _neighDist)
{
  //reset values
  m_nearBoids = 0;
  m_distance = 0;
  m_allignment =0;

  //check current boid and compare it others
  for (unsigned int i=0; i<_boidList.size();i++)
    {
      m_distance = _boidList[boidID]->getPosition()- _boidList[i]->getPosition();
      if(m_distance.length() >0 && m_distance.length() < _neighDist)// check if in neighbourhood
        {
          // add velocity
          m_allignment+=_boidList[i]->getVelocity();
          m_nearBoids++;
        }
    }
  if (m_nearBoids>0)
    {
      //divide by the counter, add velocity, clamp the allignment vector
      m_allignment=m_allignment/m_nearBoids;
      m_allignment -= _boidList[boidID]->getVelocity();
      m_allignment.clamp(_maxAccel);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Behaviour::finalBehaviourVelocity(double _cohesionTresh,
                                                             double _alignTresh,
                                                             double _seperaTresh,
                                                             double _seekTresh,
                                                             double _wanderTresh)
{
 //reset values
  m_behaveVelocity=0;
  //calcualte the final velocity
  m_behaveVelocity =
      _cohesionTresh*  m_cohesion
      +_alignTresh*    m_allignment
      +_seperaTresh*   m_seperation
      +_seekTresh*     m_seeking
      +_wanderTresh *    m_wander;

  if(m_behaveVelocity != 0) //check to avoid normalization erros
    {
      //nomralize
      m_behaveVelocity.normalize();
    }

}




