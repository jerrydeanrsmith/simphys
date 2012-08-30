/*
  Simple 2D vector class, to demo test code.
  \author Richard Kelley
*/

#ifndef VEC2_H
#define VEC2_H

namespace simphys {

  class vec2 { 
  private:
    // Note the use of floats here. Why floats?
    float x;
    float y;

  public:
    vec2(float x_, float y_);
    
    /*
      Return the norm of the vector.
     */
    inline float norm() const;

    /*
      Return the square of the norm. for efficiency.
    */
    inline float norm_sq() const;
    
    /*
      Return the unit vector pointing in the same direction as this vector
    */
    vec2 normalized() const;

    /*
      Normalize this vector.
    */
    void normalize();

    /* 
       getters and setters 
       
       You could reasonably argue that it would be better not to have
       these, and to make this a struct instead of a class. That may
       have some merit, but we'll stick with this approach unless it
       becomes infeasible.
    */
    float getX() const {
      return x;
    }
    float getY() const {
      return y;
    }
    void setX(float new_x) {
      x = new_x;
    }
    void setY(float new_y) {
      y = new_y;
    }
    
  };

  vec2 operator+(const vec2& v1, const vec2& v2);
  vec2 operator-(const vec2& v1, const vec2& v2);
  vec2 operator*(float, const vec2& v2);
  vec2 operator*(const vec2& v2, float);

}


#endif // VEC2_H
