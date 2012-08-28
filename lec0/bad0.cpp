/*
  An example of a bad C++ program.
  \author Richard Kelley
*/

#include <iostream>

using namespace std;

float print_all(float *array, int num) {
  for (int i = 0; i < num; ++i) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main(int argc, char **argv) {
  for (int i = 0; i < 10; ++i) {
    // manually allocate floats
    float *f = new float[10];

    // initialize array
    for (int j = 0; j < 10; ++j) {
      f[j] = 10 - j;
    }

    // print it
    print_all(f, 10);
  }

  return 0;
}
