#include <stdio.h>
#include <stdlib.h>

/*
  A node in a linked list for chars.
*/
typedef struct char_node {
  struct char_node* next_node;
  char value;
} char_node;

/*
  Function to create a char_node with the given value.  Ownership of
  the pointer is transferred to the caller.
*/
char_node *create_char_node(char value) {
  struct char_node *node = (struct char_node*) malloc(sizeof(struct char_node));
  node->next_node = NULL;
  node->value = value;
  return node;
}

/*
  A singly-linked list of char_nodes.
*/
typedef struct char_list {
  struct char_node *first;
  struct char_node *last;
} char_list;

/*
  Function for creating an empty singly-linked list.
*/
char_list *create_char_list() {
  char_list* lst = (char_list*) malloc(sizeof(char_list));
  lst->first = NULL;
  lst->last = lst->first;
}

/*
  Print the given list.
*/
void print_list(char_list *l) {
  printf("List: ");
  char_node *n = l->first;
  while (n != NULL) {
    printf("%c ", n->value);
    n = n->next_node;
  }
  printf("\n");
}

/*
  Add the given node to the end of the list l.
*/
void add_node(char_list *l, char_node *n) {
  char_node *p = l->first;
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
  char_list *l = create_char_list();
  print_list(l);
  char_node *n1 = create_char_node('f');
  add_node(l, n1);
  print_list(l);
  char_node *n2 = create_char_node('o');
  add_node(l, n2);
  print_list(l);
  char_node *n3 = create_char_node('o');
  add_node(l, n3);
  print_list(l);

  free(n3); free(n2); free(n1); free(l);
}
