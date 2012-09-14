/*
  This file uses templates to implement a more generic linked list
  class. Rather than repeat ourselves by writing a new linked list for
  each type we want to put in a list, we create a *generic* linked
  list that takes the type of its element as a template parameter.

  The basic idea behind the class is that the two linked list
  implementations don't really differ that much. Whenever this
  happens, there's a good chance that we can refactor the code using
  either templates (as we'll see below) or some cleverness with
  inheritance.

  \author Richard Kelley
*/

#include <iostream>

// remember that this is where shared_ptr comes from.
#include <memory>

using std::shared_ptr;

/*
  We prefix the class declaration with template<typename T>. When we
  do this, everything from that point to the end of the declaration is
  in the scope of the template. That means that we can use T just as
  if it were any regular type, like 'int' or 'float'. Inside the
  template declaration, we use T as a type. 

  Rather than the raw pointer that we used in the C version of the
  code (either for ints or lists), we use a shared pointer. You should
  run valgrind on this program to see that it's correctly freeing
  memory, even though we don't explicitly free anything.

  In this case, the template parameter T is the type of the object
  that the list contains.
*/
template<typename T>
struct Node {
  /*
    Outside of this struct's declaration we have to type Node<T>, but
    inside the declaration the <T> part is redundant, so we can omit
    it, as in this declaration of the shared_ptr member variable.
  */
  shared_ptr<Node> next_node;

  // Here's the value we're storing in this node. It has type T.
  T value;
  
  /*
    In this case, we're passing in a val of type T as an argument.

    Also, notice that instead of initializing next_node to 0 or NULL,
    I use the new C++11 nullptr literal. As you might guess, this
    represents a null pointer. It has type std::nullptr_t, so you
    don't have to worry about confusing 0 (the number) and 0 (the null
    pointer value).
  */
  Node(T val)
    : next_node{nullptr}
    , value{val} { }
};

/*
  Here we use T again to denote the type of element the list contains.
*/
template<typename T>
struct List {

  /*
    Even though we don't have to say List<T> inside this declaration,
    we still have to say Node<T> here. Otherwise we'd get a compiler
    error.

    Notice that templates can nest. When you use a type like Node<T>
    as a template parameter, in C++98 you need to have at least one
    space between the two '>' symbols. If you don't, C++98 interprets
    the '>>' as a right shift operator and has a syntax error. In
    C++11 the space is no longer required.
  */
  shared_ptr<Node<T> > first;
  shared_ptr<Node<T> > last;

  List() 
    : first{nullptr}
    , last{nullptr} { }

  void print();
  void add_node(shared_ptr<Node<T> > n);

  /*
    TODO - declare a remove function. The function should take a value
    of type T and remove every node in the list that contains the
    given value.
  */
  // function remove goes here
};

/*
  This is a definition of a template member function.

  Member functions of template classes are themselves templates, so
  you need the template<typename T> prefix for the function
  definition.

  The important thing to keep in mind here is that you need to be
  careful where you put the <T>. It goes by the name of the class for
  which the function is a member.
*/
template<typename T>
void List<T>::print() {
  std::cout << "List: ";
  shared_ptr<Node<T> > n = first;
  while (n != nullptr) {
    std::cout << n->value << " ";
    n = n->next_node;
  }
  std::cout << std::endl;
}

template<typename T>
void List<T>::add_node(shared_ptr<Node<T> > n) {
  shared_ptr <Node<T> > p = first;
  if (p == nullptr) {
    first = n;
    n->next_node = nullptr;
  } else {
    while (p->next_node != nullptr) {
      p = p->next_node;
    }
    p->next_node = n;
    n->next_node = nullptr;
  }
}

/*
  TODO - implement a remove function.

  The function should take a *value* v of type T and remove every node
  from the list that has a value that equals v.

  I'm not writing the signature so you can get some practice doing so
  yourself.

*/

int main() { 
  List<int> l;
  auto n1 = std::make_shared<Node<int> >(1);
  auto n2 = std::make_shared<Node<int> >(42);
  auto n3 = std::make_shared<Node<int> >(4);
  l.add_node(n1);
  l.add_node(n2);
  l.add_node(n3);
  l.print();

  // TODO - show that your remove function works for List<int>

  List<char> cl;
  auto cn1 = std::make_shared<Node<char> >('f');
  auto cn2 = std::make_shared<Node<char> >('o');
  auto cn3 = std::make_shared<Node<char> >('o');
  cl.add_node(cn1);
  cl.add_node(cn2);
  cl.add_node(cn3);

  cl.print();

  // TODO - show that your remove function works for List<char>
}

