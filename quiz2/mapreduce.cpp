/*
  A simple example of the mapreduce concept.

  This uses only the standard library. If you were to build an actual
  MapReduce library you would probably build functions, map and
  reduce, that would abstract the operations of the standard library.
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

template<typename T>
std::string print(const std::vector<T>& coll) {

  std::string result = "";
  std::vector<std::string> intermed{coll.size()};

  /*
    Convert each element to a string.
  */
  std::transform(coll.begin(), coll.end(), intermed.begin(), 
		 [](T obj) { return std::to_string(obj); });

  /*
    Add each transformed element to the result string.
  */
  std::for_each(intermed.begin(), intermed.end(), 
		[](std::string s) {
		  result += s;
		  result += " ";
		});

  return result;
  
}

int main() {
  
  std::vector<int> nums = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  std::vector<float> fnums = {1.41f, 2.71828, 3.14159, 0.57721}; 

  std::cout << print(nums) << std::endl;
  std::cout << print(fnums) << std::endl;
}
