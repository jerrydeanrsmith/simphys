/*
  Playing with computation of derivatives.
  \author Richard Kelley
*/

// for printing to standard out.
#include <iostream>

// IO manipulators for making our floats print nicely.
#include <iomanip>

/*
  This is how we get access to std::function, which is the star of
  this file.
*/
#include <functional>

/*
  We'll use this name a lot, so let's put it in a using declaration.
*/
using std::function;

/*
  Take the derivative of the function f.

  The return type of this function is function<float(float)>.

  In general the type function<S(T)> means "a function that takes an
  argument of type T and returns a result of type S." So that means
  that the derivative function returns a *function* that takes a float
  and returns a float. If you look at the math, you'll see this is
  exactly what the derivative you studied in calculus does.

  Another lesson from this code is that the "obvious" way to calculate
  derivatives is _terrible_ when used naively on a computer. We'll see
  why below, but you should avoid using this function in any context
  where accuracy matters.
*/
function<float(float)> derivative(function<float(float)> f) {
  float epsilon = 0.1f;

  // The thing we're returning here is called a "lambda." There's more
  // detail on this topic below. The only thing that's unique about
  // this one is the use of the '=' inside the brackets. This allows
  // us to access variables outside the scope of the function, in this
  // case epsilon and f.
  return [=](float x) {
      return (f(x + epsilon) - f(x - epsilon)) / (2.0f * epsilon);
    };
}

int main(int argc, char **argv) {

  /*
    Check the number of arguments to decide whether or not to show an
    example of the numerical problems with our approximate derivative.
  */
  bool big_example = false;
  if (argc < 2) {
    std::cerr << "Skipping big example." << std::endl; 
  } else {
    big_example = true;
  }

  /*
    The rhs of this statement creates an anonymous function that takes
    a float x and returns a float. The function computes the square of
    its input. The statement then assigns the function to the variable
    square, which has type function<float(float)>. We don't have to
    write that out because we're using C++11's type inference
    capabilities.

    The notation on the RHS of the assignment is what's called a
    "lambda" in C++11. Another name you may hear for this is an
    "anonymous function." The general notation is 

    [captureoptions](args) -> returntype { 
      statements;
    }

    The concept of anonymous functions exists (in varying degrees of
    complexity) in many languages (Lisp, Haskell, ML, Python, Ruby,
    and Javascript all have them more or less), but the notation here
    is maybe a bit overwhelming, even if you've used lambdas in
    another language. We'll talk about the details in class and in
    future code examples. For now the only thing that probably isn't
    obvious from the declaration is that the lambda doesn't capture
    any variables.

  */
  auto square = [](float x) -> float {
    return (x * x);
  };

  /*
    This statement uses the derivative function that we defined before
    main to create the derivative of the function we just defined in
    the statement just above this one.
  */
  auto square_prime = derivative(square);

  // Let's repeat the above, except with a linear function.
  auto linear = [](float x) -> float {
    return 5.0f * x + 2.0;
  };
  auto linear_prime = derivative(linear);

  // print out a table of values for squaring function.
  std::cout  << "x" << "\t" << "x^2" << "\t" << "dx^2" << "\t" << "2x" << "\t" << "dx^2 - 2x" << std::endl;
  for (float x = -1.0; x < 1.1; x += 0.1) {
    std::cout << std::fixed 
	      << std::setprecision(4) 
	      << x << "\t" 
	      << square(x) << "\t" 
	      << square_prime(x) << "\t" 
	      << 2.0f * x << "\t" 
	      << 2.0f * x - square_prime(x) 
	      << std::endl;
  }

  std::cout << std::endl << std::endl;

  // print out a table of values for a linear function.
  std::cout  << "x" << "\t" << "5x + 2" << "\t" << "d(5x+2)" << "\t" << "5" << "\t" << "d(5x+2) - 5" << std::endl;
  for (float x = -1.0; x < 1.1; x += 0.1) {
    std::cout << std::fixed
              << std::setprecision(4)
              << x << "\t"
              << linear(x) << "\t"
              << linear_prime(x) << "\t"
              << 5.0f << "\t"
              << 5.0f - linear_prime(x)
              << std::endl;
  }

  // if enabled, show an example where floating point is a problem.
  if (big_example) {
    float big_num = 1024.2f;
    std::cout << "For x = " << big_num 
	      << ", f(x) = " << square(big_num) 
	      << " and f'(x) = " << square_prime(big_num) 
	      << " but 2x = " << 2.0f * big_num
	      << " for a difference of " << 2.0f * big_num - square_prime(big_num)
	      << ". huh." << std::endl;
  }
}
