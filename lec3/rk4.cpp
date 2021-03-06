/*
  Implementation of 4th-order Runge-Kutta method.
 
  This is just a demonstration of the equations. You'll have to do
  some work to get the equations implemented in a form suitable for
  using in a physics engine.

  \author Richard Kelley
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

using std::function;

/*
  Integrate the equation dx/dt = f(x,t) using the 4th-order RK method.
  
  \param f the RHS of the equation we're integrating
  \param t the current time
  \param x the current position, x(t)
  \param duration the time delta
*/
float rk4(function<float(float, float)> f, float t, float x, float duration) {
  float f1 = duration * f(t, x);
  float f2 = duration * f(t + 0.5f * duration, x + 0.5f * f1);
  float f3 = duration * f(t + 0.5f * duration, x + 0.5f * f2);
  float f4 = duration * f(t + duration, x + f3);
  return x + (1.0f/6.0f) * (f1 + 2.0f * f2 + 2.0f * f3 + f4);
}

/*
  This is an example of integrating the velocity to get the position.

  We assume that an object at an initial height of 1000.0 meters is
  dropped. We also assume that the only force acting on the object is
  gravity. We use RK4 to integrate the position over time. We then
  compare with the solution we obtain analytically.
 */
int main() {
  // parameters of our time-keeping.
  int frequency = 120;
  int millisPerTick = int{1000 * (1.0 / frequency)};
  std::chrono::milliseconds tick{millisPerTick};

  // The velocity at time t and position x.
  auto f = [](float t, float x) {
    return -9.8f * t;
  };

  // The initial position of our object.
  float position = 1000.0f;

  float time = 0.0f;
  while (time < 1.0f) {
    // update the position using rk4.
    position = rk4(f, time, position, (1.0f / frequency));

    // update time.
    time += (1.0f / frequency);

    // This sleeping is not necessary for the math to work out, but
    // you'll want to start getting familiar with time and threads.
    std::this_thread::sleep_for(tick);
  }

  // Math tells us how far the object should have fallen.
  float expectedY = 1000.0f - 9.8 * time * time * 0.5f;

  // output.
  std::cout << "The final position is: " << position << std::endl;
  std::cout << "The expected position is: " << expectedY << std::endl;
  std::cout << "The difference is: " << position - expectedY << std::endl;
}
