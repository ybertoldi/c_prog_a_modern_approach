#include "stackADT.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct stack_type {
  Item contents[STACK_SIZE];
  int top;
};

static void terminate(const char *message) {
  printf("%s", message);
  exit(EXIT_FAILURE);
}

Stack create() {
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL) {
    terminate("stack create: could not allocate memory for new stack");
  }
  s->top = 0;
  return s;
}

void destroy(Stack s) { free(s); }

void make_empty(Stack s) { s->top = 0; }

bool is_empty(Stack s) { return s->top <= 0; }

bool is_full(Stack s) { return s->top >= STACK_SIZE; }

void push(Stack s, Item i) {
  if (is_full(s)) {
    terminate("push: stack is full");
  }
  s->contents[s->top++] = i;
}

Item pop(Stack s) {
  if (is_empty(s)) {
    terminate("pop: stack is empty");
  }
  return s->contents[--s->top];
}
