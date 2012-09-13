/*
  Implementation of the vec3 class.

  Wherever you see TODO, you should fill in code to perform the
  required function.

  I decided not to use a namespace declaration or directive, so this
  file is more verbose than you would normally see in the real
  world. The only reason for this is to show you how a custom
  namespace gets used.

  \author Richard Kelley

  TODO - fill in your name as an author
  \author 
*/

#include "vec3.h"

simphys::vec3::vec3(float x_, float y_, float z_) 
  : x(x_), y(y_), z(z_) {
  // TODO - make sure you understand what this notation for a
  // constructor is doing. If you haven't seen this before, bring it
  // up on Piazza and we can talk about initializer lists.
}

float simphys::vec3::norm() const {
  // TODO - fill in implementation for quiz 1.
  return 0.0f;
}

float simphys::vec3::norm_sq() const {
  // TODO - fill in implementation for quiz 1.
  return 0.0f;
}

simphys::vec3 simphys::vec3::normalized() const {
  // TODO - fill in implementation for quiz 1.
  return vec3(0.0f, 0.0f, 0.0f);
}

void simphys::vec3::normalize() { 
  // TODO - fill in implementation for quiz 1.
}

float simphys::vec3::dotProduct(const simphys::vec3& other) const {
  // TODO - fill in implementation for quiz 1.
  return 0.0f;
}

simphys::vec3 simphys::vec3::crossProduct(const simphys::vec3& other) const {
  // TODO - fill in implementation for quiz 1.
  return vec3(0.0f, 0.0f, 0.0f);
}

float simphys::vec3::getX() const {
  // TODO - fill in implementation for quiz 1.
  return 0.0f;
}

float simphys::vec3::getY() const {
  // TODO - fill in implementation for quiz 1.
  return 0.0f;
}

float simphys::vec3::getZ() const {
  // TODO - fill in implementation for quiz 1.
  return 0.0f;
}

void setX(float newX) {
  // TODO - fill in implementation for quiz 1.
}

void setY(float newY) {
  // TODO - fill in implementation for quiz 1.
}

void setZ(float newZ) {
  // TODO - fill in implementation for quiz 1.
}

simphys::vec3 simphys::operator+(const simphys::vec3& v1, const simphys::vec3& v2) {
  // TODO - fill in implementation for quiz 1.
  return vec3(0.0f, 0.0f, 0.0f);
}

simphys::vec3 simphys::operator-(const simphys::vec3& v1, const simphys::vec3& v2) {
  // TODO - fill in implementation for quiz 1.
  return vec3(0.0f, 0.0f, 0.0f);
}

simphys::vec3 simphys::operator*(float c, const simphys::vec3& v1) {
  // TODO - fill in implementation for quiz 1.
  return vec3(0.0f, 0.0f, 0.0f);
}

simphys::vec3 simphys::operator*(const simphys::vec3& v1, float c) {
  // TODO - fill in implementation for quiz 1.
  return vec3(0.0f, 0.0f, 0.0f);
}
