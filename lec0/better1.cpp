#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

/*
  Something to watch out for here is the argument copy. It may or may
  not be a problem. We'll talk about why in a later lecture. How could
  we avoid the issue if we wanted?
 */
void print_all(vector<float> vec) {
  for (auto f : vec) {
    cout << f << " ";
  }
}

int main(int argc, char **argv) {
  
  for (int i = 0; i < 10; ++i) {
    auto v = vector<float>(10);

    cout << &v << endl;
    
    for (int j = 0; j < 10; ++j) {
      v[j] = 10 - j;
    }

    print_all(v);
    cout << endl;
  }
}
