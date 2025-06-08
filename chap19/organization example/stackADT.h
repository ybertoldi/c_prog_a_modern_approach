#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack create(void);
void destroy(Stack);
void make_empty(Stack);
bool is_empty(Stack);
bool is_full(Stack);
void push(Stack,Item);
Item pop(Stack);

#endif
