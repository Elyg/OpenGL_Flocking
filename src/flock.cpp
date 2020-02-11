#include "boid.h"
#include "flock.h"
#include <ngl/Random.h>
#include <vector>
#include <ngl/Vec3.h>


Flock::Flock() //default ctror
{}
Flock::~Flock()//dtor
{}
//----------------------------------------------------------------------------------------------------------------------
void Flock::boidFlock(int _boidNum, std::vector<Boid*> &_boidList, double _radius)
{
  //iterate through and add to list
  for (unsigned int i=0;i<_boidNum;i++ )
    {
      //random point for position
      ngl::Random *rng=ngl::Random::instance();
      ngl::Vec3 r=rng->getRandomVec3();
      //random velocity vector - currently not using
      ngl::Random *rng3=ngl::Random::instance();
      ngl::Vec3 j =rng3->getRandomNormalizedVec3();
      // create boid
      m_boid = new Boid (r*30, j*10, _radius);
      _boidList.push_back(m_boid);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void Flock::flockClear(std::vector<Boid*> &_boidList)
{
  //method to clear boids list
  _boidList.clear();
}


