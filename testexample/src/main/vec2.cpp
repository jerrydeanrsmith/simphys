#include <cmath>
#include "vec2.h"

namespace simphys {

  using std::sqrt;
  
  vec2::vec2(float x_, float y_) 
    : x(x_), y(y_) {
    // nothing more to do here.
  }
  
  float vec2::norm() const {
    return sqrt(x*x + y*y);
  }

  float vec2::norm_sq() const {
    return x*x + y*y;
  }

  vec2 vec2::normalized() const {
    float n = norm();
    return vec2(x / n, y / n);
  }

  void vec2::normalize() { 
    float n = norm();
    x /= n;
    y /= n;
  }

  vec2 operator+(const vec2& v1, const vec2& v2) {
    return vec2(v1.getX() + v2.getX(),
		v1.getY() + v2.getY());
  }

  vec2 operator-(const vec2& v1, const vec2& v2) {
    return vec2(v1.getX() - v2.getX(),
		v1.getY() - v2.getY());
  }

  vec2 operator*(float c, const vec2& v2) {
    return vec2(c * v2.getX(), c * v2.getY());
  }

  vec2 operator*(const vec2& v2, float c) {
    return vec2(v2.getX() * c, v2.getY() * c);
  }

}
