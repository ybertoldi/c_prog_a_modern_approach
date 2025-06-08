#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#define STACK_SIZE 100

typedef struct {
  int contents[STACK_SIZE];
  int top;
} Stack;

void make_empty(Stack *);
bool is_empty(Stack *);
bool is_full(Stack *);
void push(Stack *, int);
int pop(Stack *);

#endif
