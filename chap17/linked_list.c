#include <stdio.h>
#include <stdlib.h>
typedef struct t_node {
  int value;
  struct t_node *next;
} node;

void list_add(node **head, int n) {
  node *new;
  new = malloc(sizeof(node));
  if (new == NULL) {
    printf("Error: malloc failed in node_add");
    exit(EXIT_FAILURE);
  }

  new->value = n;
  new->next = *head;
  *head = new;
}

int list_indexof_value(node *list, int value) {
  int i = 0;
  while (list != NULL && list->value != value) {
    list = list->next;
    i++;
  }
  if (list == NULL)
    return -1;

  return i;
}

int list_get(node *list, int idx) {
  node *p;
  p = list;
  for (int i = 1; i <= idx; i++) {
    p = p->next;
    if (p == NULL) {
      printf("index out of bounds\n");
      exit(EXIT_FAILURE);
    }
  }

  return p->value;
}
