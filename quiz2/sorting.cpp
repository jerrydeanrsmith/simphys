#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

struct Person {
  std::string first_name;
  std::string last_name;
};

struct PersonComparator {
  bool operator()(const Person& p1, const Person& p2) {
    return p1.last_name < p2.last_name;
  }
};

int main() {
  std::vector<Person> instructors = { {"Thomas", "Kelly"}, {"Richard", "Kelley"} };

  for (const auto& p : instructors) {
    std::cout << p.first_name << " " << p.last_name << std::endl;
  }

  auto comp = [](const Person& p1, const Person& p2) {
    return p1.last_name < p2.first_name;
  };

  std::sort(instructors.begin(), instructors.end(), PersonComparator());
  
  // here's the other way to do it
  //std::sort(instructors.begin(), instructors.end(), comp);


  std::cout << std::endl;
  std::cout << "After sorting: " << std::endl;
  for (const auto& p : instructors) {
    std::cout << p.first_name << " " << p.last_name << std::endl;
  }
}
