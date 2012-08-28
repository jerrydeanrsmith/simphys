/*
  An improvement over bad0.cpp
  \author Richard Kelley
*/

#include <iostream>
#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;
using std::cout;
using std::endl;

void print_all(shared_ptr<vector<float> > array_ptr) {
  for (auto f : *array_ptr) {
    std::cout << f << " ";
  }
}

int main(int argc, char **argv) {
  for (int i = 0; i < 10; ++i) {
    shared_ptr<vector<float> > f = shared_ptr<vector<float> >(new vector<float>(10));

    for (int j = 0; j < 10; ++j) {
      (*f)[j] = 10 - j;
    }
    print_all(f);
    cout << endl;
  }
  
  return 0;
}
