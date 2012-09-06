#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {

  // let's try to find out how many concurrent threads the hardware
  // can support
  auto hardware_threads = std::thread::hardware_concurrency();

  // if hardware_concurrency returns 0, let's just make something up.
  if (0 == hardware_threads) {
    hardware_threads = 4;
  }

  // we'll store our threads in a vector, initialized to hold
  // hardware_threads many threads.
  std::vector<std::thread> threads{hardware_threads};

  // initialize each thread with a lambda. The function just
  // increments an int indefinitely.
  for (auto& t : threads) {
    t = std::thread{ 
      [](){
	int i = 0;
	while(1) {
	  i++;
	}
      }
    };
  }
  
  // join each thread so that main doesn't exit.
  for_each (threads.begin(), threads.end(), std::mem_fn(&std::thread::join));

}
