#include <iostream>
#include <chrono>
#include <thread>

// do work.
void work() {
  std::chrono::milliseconds tick{16};
  std::this_thread::sleep_for(tick);
}

void loop() {
  auto start_time = std::chrono::high_resolution_clock::now();
  auto end_time = start_time;

  // real time between frames.
  float dt = 0.0;

  while(1) {
    // get the start time
    start_time = std::chrono::high_resolution_clock::now();

    // do stuff
    work();

    // get the end time
    end_time = std::chrono::high_resolution_clock::now();

    // figure out the difference
    dt = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    // print the difference
    std::cout << "dt = " << dt << std::endl;
  }

}

int main() {
  loop();
}
