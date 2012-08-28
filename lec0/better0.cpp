/*
  An improvement over bad0.cpp
  \author Richard Kelley
*/

// for standard output
#include <iostream>

// for smart pointers
#include <memory>

// for the container
#include <vector>

/*
  Instead of polluting the global namespace with a using directive,
  we have using declarations for only the names we care about.

  You should get out of the habit of writing using directives for the
  standard library - it's almost never necessary, and in larger
  projects where you use multiple libraries, there's a nontrivial
  chance that a careless using directive could introduce a naming
  conflict with another library.

  Note that in throwaway code, using namespace std is probably
  ok. Just be sure that it's actually throwaway code.
 */
using std::vector;
using std::shared_ptr;
using std::cout;
using std::endl;

/*
  We're no longer returning a float (which couldn't possibly make
  sense).

  By using a standard library container (the vector), we no longer
  have to pass in the number of elements to process, which means we
  don't have to worry about a mistaken or malicious user passing in an
  incorrect size.

  The std::shared_ptr is a "smart pointer." A smart pointer has the
  semantics of a regular pointer, but may also perform additional work
  to make use of the pointer easier or safer. A "shared pointer" is
  what's known as a "reference-counted smart pointer." In addition to
  regular pointer semantics, the shared pointer keeps a "reference
  count," which is just the number of references that other objects
  have to it. When that number reaches zero, the pointer is
  deallocated. This means that you never have to write an explicit
  delete when using a shared_ptr.

  In the new C++11 standard, shared pointers are just one type of
  smart pointer. The other major type is unique_ptr, which we'll talk
  about soon.

  You should get out of the habit of writing "raw pointers." They're
  dangerous and usually not necessary. In case you can't use C++11
  yet, the Boost library has smart pointers with similar
  semantics. Start using smart pointers as a default, and only move
  back to raw pointers when you have a good reason to do so.
 */
void print_all(shared_ptr<vector<float> > array_ptr) {

  /*
    Rather than explicitly index into the vector argument, we use two
    new C++ features to produce a cleaner and (probably) easier to
    understand function.

    The keyword "auto" in C++ can be used when declaring new
    variables. When you declare a variable "auto", you're telling the
    compiler that you want it to perform "type inference." Basically,
    you're saying "Compiler, figure out the type for me." This is
    common in functional languages like Haskell and Scala, but is
    useful in many cases in C++. In this case the expression "auto f"
    means that the compiler should figure out the type of f based on
    what's on the other side of the ":".

    C++11 also introduces a new type of loop. This is called a
    "range-based for loop," and it allows us to iterate through a
    collection. In this case, the variable f is bound to each element
    of *array_ptr in order, and the statements in the loop body are
    executed with this binding. This means we don't have to worry
    about index checking or iterators any more.
    
    When iterating over collections, you should get in the habit of
    using the range-based for loop, as long as you know that you're
    working with C++11.
   */
  for (auto f : *array_ptr) {
    cout << f << " ";
  }
}

int main(int argc, char **argv) {

  using std::make_shared;

  for (int i = 0; i < 10; ++i) {

    /*
      This is the last new thing. We can use std::make_shared<T>() to
      create a shared pointer to T. We pass in the arguments that we
      would pass to T's constructor, and get back a shared_ptr to T.

      Note that in this case we use the "auto" keyword to spare us
      from some (keyboard) typing.
     */
    auto v = make_shared<vector<float> >(10);

    for (int j = 0; j < 10; ++j) {
      (*v)[j] = 10 - j;
    }
    print_all(v);
    cout << endl;
  }
  
  return 0;
}
