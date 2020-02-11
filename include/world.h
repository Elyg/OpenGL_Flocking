#ifndef WORLD_H
#define WORLD_H

#include "boid.h"
#include "ngl/Vec3.h"
#include <boost/foreach.hpp>

/// @file world.h
/// @brief a class to create the world
/// @author original author Eligijus Titas
/// @version 1.0
/// @date 15/05/15
/// @class World
/// @brief main class to create the world object

//----------------------------------------------------------------------------------------------------------------------
/// @brief structure for the Wall
/// @param [in] size wall list
/// @param [in] a point X value
/// @param [in] b point Y value
/// @param [in] c point Z value
/// @param [in] d normal of the wall
/// @param [in] draw toggle
//----------------------------------------------------------------------------------------------------------------------
typedef struct WALL{
  ngl::Vec3   centre;
  float   size;
  float   a;
  float   b;
  float   c;
  float   d;
  bool draw;
} Wall;

class World
{  
public:
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ctor for the World object
  /// @param [in] _octreeDiv octree division size
  /// @param [in] _bb bounding box size
  //----------------------------------------------------------------------------------------------------------------------
  World();
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for checking collisons against the walls
  /// @param [in] _walls wall list
  /// @param [in] _maxVelocity maximum velocity
  /// @param [in] _maxAccel maximum acceleration
  //----------------------------------------------------------------------------------------------------------------------
  void collisionWithWalls(std::vector <Wall *> &_walls,Boid *_boid, float _maxVelocity, float _maxAccel);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for adding walls
  /// @param [in] _walls list of walls
  /// @param [in] _point position of the wall
  /// @param [in] _size size of the wall
  /// @param [in] _normal set normals
  /// @param [in] _draw toggle drawing for the bbox
  //----------------------------------------------------------------------------------------------------------------------
  void addNewWall(std::vector <Wall *> &_walls, ngl::Vec3 _point, float _size, ngl::Vec3 _normal, bool _draw);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for adding boids ot octree to check collisions
  /// @param [in] _boidList list boids to check
  //----------------------------------------------------------------------------------------------------------------------
  void collisionBoids(std::vector<Boid*> &_boidList);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for clearing the boids out of the list
  /// @param [in] _nearList lsit of boids to clear
  //----------------------------------------------------------------------------------------------------------------------
  void clearBoids(std::vector<Boid *> &_nearList);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for setting the test boid to check collisons
  /// @param [in] _test set the boids
  //----------------------------------------------------------------------------------------------------------------------
  void setTestBoid(Boid* &_test);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method for setting the test boid to check collisons
  /// @param [in] _vec intake vecotr y
  /// @return rotation values for rotating the bounding box
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 getRotationFromY(ngl::Vec3 _vec) const;

private:

};
#endif // WORLD_H
