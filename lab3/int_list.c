/*
  This is a C implementation of some of the functionality of a linked
  list of ints. 

  \author Richard Kelley
*/

#include <stdio.h>

// this is where C's memory management functions are found.
#include <stdlib.h>

/*
  A node in a linked list for ints.

  The pattern 

  typedef ... {
    ...
  } name; 

  is common in C. In C, you can't just say struct foo {}; and then
  later declare a variable of type foo. Instead, you always have to
  type the keyword struct unless you use the typedef. This is one
  piece of syntax that C++ does rather well.
*/
typedef struct int_node {
  struct int_node* next_node;
  int value;
} int_node;

/*
  Function to create an int_node with the given value.  Ownership of
  the pointer is transferred to the caller.
*/
int_node *create_int_node(int value) {
  // C uses the function malloc instead of the operator new 
  // to allocate memory.
  struct int_node *node = (struct int_node*) malloc(sizeof(struct int_node));
  node->next_node = NULL;
  node->value = value;
  return node;
}

/*
  A singly-linked list of int_nodes.
*/
typedef struct int_list {
  struct int_node *first;
  struct int_node *last;
} int_list;

/*
  Function for creating an empty singly-linked list.
*/
int_list *create_int_list() {
  int_list* lst = (int_list*) malloc(sizeof(int_list));
  lst->first = NULL;
  lst->last = lst->first;
}

/*
  Print the given list.
*/
void print_list(int_list *l) {
  // C doesn't have cout, so we have to use printf.
  printf("List: ");
  int_node *n = l->first;
  while (n != NULL) {
    printf("%d ", n->value);
    n = n->next_node;
  }
  printf("\n");
}

/*
  Add the given node to the end of the list l.
*/
void add_node(int_list *l, int_node *n) {
  int_node *p = l->first;
  // handle empty list
  if (p == NULL) {
    l->first = n;
    n->next_node = NULL;
  } else {
    while (p->next_node != NULL) {
      p = p->next_node;
    }
    p->next_node = n;
    n->next_node = NULL;
  }
}

int main() {
  int_list *l = create_int_list();
  print_list(l);
  int_node *n1 = create_int_node(1);
  add_node(l, n1);
  print_list(l);
  int_node *n2 = create_int_node(42);
  add_node(l, n2);
  print_list(l);
  int_node *n3 = create_int_node(3);
  add_node(l, n3);
  print_list(l);

  free(n3); free(n2); free(n1), free(l);
}
