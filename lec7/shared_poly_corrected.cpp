/*
  A program demonstrating polymorphism in C++ via the virtual keyword.

  \author Richard Kelley
*/

#include <memory>
#include <iostream>
#include <vector>

class Animal {
public:
  virtual void speak() const {
    std::cout << "Animal noise" << std::endl;
  }
};

class Dog : public Animal {
public:
  void speak() const {
    std::cout << "Woof!" << std::endl;
  }
};

class Cat : public Animal {
public:
  void speak() const {
    std::cout << "Meow!" << std::endl;
  }
};

int main() {
  std::vector<std::shared_ptr<Animal> > zoo{2};
  
  zoo[0] = std::make_shared<Dog>();
  zoo[1] = std::make_shared<Cat>();

  for (const auto& a : zoo) {
    a->speak();
  }
}
