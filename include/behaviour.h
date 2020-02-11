#ifndef BEHAVIOUR_H__
#define BEHAVIOUR_H__

#include <ngl/Vec3.h>
#include <vector>
#include <boid.h>

/// @file behaviour.h
/// @brief a class for managing behaviours for boids
/// @author original author Eligijus Titas
/// @version 1.0
/// @date 15/05/15
/// @class Behaviour
/// @brief managing boid's behaviours
class Behaviour
{
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ctor for Behaviour class
  //----------------------------------------------------------------------------------------------------------------------
  Behaviour();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief dtor for Behaviour class
  //----------------------------------------------------------------------------------------------------------------------
  ~Behaviour();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for calcualting the cohesion behaviour
  /// @param [in] boidID current boids ID
  /// @param [in] _boidList all boids' list
  /// @param [in] _nearList nearest boids list
  /// @param [in] _maxVelocity max velocity value
  /// @param [in] _maxAcce max acceleration value
  /// @param [in] _neighDistl neighboorhood radius
  //----------------------------------------------------------------------------------------------------------------------
  void Cohesion(unsigned int boidID , std::vector<Boid *> &_boidList, std::vector<Boid *> &_nearList, double _maxVelocity, double _maxAcce, double _neighDistl);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for calcualting the allignment behaviour
  /// @param [in] boidID current boids ID
  /// @param [in] _boidList all boids' list
  /// @param [in] _maxVelocity max velocity value
  /// @param [in] _maxAcce max acceleration value
  /// @param [in] _nearList nearest boids list
  /// @param [in] _neighDist neighboorhood radius
  //----------------------------------------------------------------------------------------------------------------------
  void Allignment(unsigned int boidID , std::vector<Boid *> &_boidList, double _maxAccel, double _maxVelocity, std::vector<Boid *> &_nearList, double _neighDist);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for calcualting the seperation behaviour
  /// @param [in] boidID current boids ID
  /// @param [in] _boidList all boids' list
  /// @param [in] _nearList nearest boids list
  /// @param [in] _maxVelocity max velocity value
  /// @param [in] _maxAcce max acceleration value
  /// @param [in] _seperationDist seperation radius
  //----------------------------------------------------------------------------------------------------------------------
  void Seperation(unsigned int boidID , std::vector<Boid *> &_boidList, std::vector<Boid *> &_nearList, double _maxVelocity, double _maxAccel, double _seperationDist);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for calcualting the seek behaviour
  /// @param [in] _target position vector of the desired target
  /// @param [in] _currentVel boid's current velocity vector
  /// @param [in] _maxVel max velocity value
  /// @param [in] _maxAccel max acceleration value
  /// @param [in] _pos current position of the boid
  //----------------------------------------------------------------------------------------------------------------------
  void Seek(const ngl::Vec3 &_target, const ngl::Vec3 &_currentVel, double _maxVel, double _maxAccel, const ngl::Vec3 &_pos);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for calcualting theWander behaviour
  /// @param [in] _vel boid leader current velocity
  /// @param [in] _nearList boid leader current position
  /// @param [in] _maxAccel maximum acceleration
  /// @param [in] _wanderAngle wandering angle
  //----------------------------------------------------------------------------------------------------------------------
  void Wander(const ngl::Vec3 _vel, std::vector<Boid *> _nearList, float _maxAccel, double _wanderAngle);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for calcualting the angles used in the wander behaviour
  /// @param [in] _vec boid velocity
  /// @param [in] _angle current angle
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 setAngle(ngl::Vec3 _vec, double _angle);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for combining all behaviours to the final velocity  vector
  /// @param [in] _cohesionTresh value for cohesion treshold
  /// @param [in] _alignTresh value for allignment treshold
  /// @param [in] _seperaTresh value for seperation treshold
  /// @param [in] _seekTresh value for seek treshold
  /// @param [in] _leadTresh value for leadership treshold
  /// @param [in] _wanderTresh value for wander treshold
  //----------------------------------------------------------------------------------------------------------------------
  void finalBehaviourVelocity(double _cohesionTresh, double _alignTresh, double _seperaTresh, double _seekTresh, double _wanderTresh);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for getting the seek behaviour velocity
  /// @return seek behaviour velocity
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 getSeek(){return m_seeking;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for getting the seek leadership behaviour velocity
  /// @return  seek leadership behaviour velocity
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 getFinalBehaviourVelocity(){return m_behaveVelocity;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the current boid's position
  /// @param [in] _pos value to get position
  //----------------------------------------------------------------------------------------------------------------------
  void getPos(ngl::Vec3 _pos);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to calcualte the nearby boids
  /// @param [in] boidID boid's ID
  /// @param [in] _boidList list of boids to check
  /// @param [in] _neighDist neighbohood distance
  //----------------------------------------------------------------------------------------------------------------------
  void neighBoids(int boidID, std::vector <Boid*> &_boidList, double _neighDist);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to clear the boid list
  //----------------------------------------------------------------------------------------------------------------------
  void neighClear();

private:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief cohesion  behaviour value
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_cohesion;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief allignment behaviour value
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_allignment;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief seperation behaviour value
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_seperation;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief seek behaviour value
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_seeking;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief final velocity of the behaviours
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_behaveVelocity;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief behind distance for leaderhsip behaviour
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_behind;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ahead distance for leaderhsip behaviour
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_ahead;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief current position  of the boid
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_pos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief desired velocity for seek behaviour
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_desiredVelocity;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief distance behind the leader
  //----------------------------------------------------------------------------------------------------------------------
  float m_leadBehindDist;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief maximum velocity
  //----------------------------------------------------------------------------------------------------------------------
  float m_maxVelocity;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief maximum acceleration
  //----------------------------------------------------------------------------------------------------------------------
  float m_maxAccel;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief distance vector between current and test boid
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_distance;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief wander behaviour value
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_wander;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief list for nearby boids
  //----------------------------------------------------------------------------------------------------------------------
  std::vector <Boid *> m_nearbyBoids;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief counter for boids
  //----------------------------------------------------------------------------------------------------------------------
  int m_nearBoids;
};
#endif // BEHAVIOUR
