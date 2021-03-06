#ifndef Boid_H__
#define Boid_H__

#include <ngl/Vec3.h>
#include <ngl/Mat4.h>
#include <vector>
#include <ngl/Transformation.h>
#include <ngl/Camera.h>

/// @file boid.h
/// @brief a class for creating a boid
/// @author original author Eligijus Titas
/// @version 1.0
/// @date 15/05/15
/// @class Boid
/// @brief main boid creation class
class Boid
{
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ctor for Boid object
  /// @param [in] _pos the position of the boid
  /// @param [in] _dir the initial velocity of the boid
  //----------------------------------------------------------------------------------------------------------------------
  Boid(ngl::Vec3 _pos, ngl::Vec3 _dir, double _radius);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief copy ctor for the boid class
  //----------------------------------------------------------------------------------------------------------------------
  Boid(const Boid &);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to update the position
  //----------------------------------------------------------------------------------------------------------------------
  void updatePos();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to update the velocity
  /// @param [in] _dir the velocity of the boid
  /// @param [in] _maxVelocity the maximum velocity of the boid
  /// @param [in] _maxAccel the maximum acceleration of the boid
  //----------------------------------------------------------------------------------------------------------------------
  void updateVelocity(ngl::Vec3 _dir, double _maxVelocity, double _maxAccel);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to update the rotation from the given velocity vector
  /// @param [in] _dir the velocity of the boid
  /// @param [in] _rot the velocity vector to create the rotations from
  //----------------------------------------------------------------------------------------------------------------------
  void updateRot();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the position
  /// @param [in] _pos position to set
  //----------------------------------------------------------------------------------------------------------------------
  void setPosition(ngl::Vec3 _pos);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the velocity
  /// @param [in] _vel set velocity vector
  /// @param [in] _maxVelocity set maximum velocity
  /// @param [in] _maxAccel set maximum acceleration
  //----------------------------------------------------------------------------------------------------------------------
  void setVelocity(ngl::Vec3 _vel, double _maxVelocity, double _maxAccel);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set the position
  /// @param [in] _pos set the position
  //----------------------------------------------------------------------------------------------------------------------
  void updatePos(ngl::Vec3 _pos);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the position value
  /// @return  the position vector of the boid
  //----------------------------------------------------------------------------------------------------------------------
  inline const ngl::Vec3 getPosition() const{return m_pos;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the velocity
  /// @return  the position vector of the boid
  //----------------------------------------------------------------------------------------------------------------------
  inline const ngl::Vec3 getVelocity() const {return m_velocity;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the rotation value
  /// @return  the rotation of the boid
  //----------------------------------------------------------------------------------------------------------------------
  inline const ngl::Vec3 getRot() const {return m_rot;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to get the sight radius of the boid
  /// @return  the radius of the boid
  //----------------------------------------------------------------------------------------------------------------------
  const float getRadius() const {return m_radius;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method to set boids radius
  //----------------------------------------------------------------------------------------------------------------------
  void setRadius(double _radius);
  inline const ngl::Mat4 getRotMat() const {return m_rotMat;}
private:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief boid's position
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_pos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief boid's velocity
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_velocity;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief boid last position
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_lastPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief boid' last position's desired velocity for the seeking behaviour
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_desiredVelocity;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief boid' rotation values
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_rot;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief boid's neighboorhood
  //----------------------------------------------------------------------------------------------------------------------
  float m_radius;
  ngl::Mat4 m_rotMat;
};
#endif // BOID

