#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000
static int stack[STACK_SIZE];
static int sp = 0;

static void terminate(const char* message){
	printf("%s", message);
	exit(EXIT_FAILURE);
}

void make_empty(){
	sp = 0;
}

bool is_empty(){
	return sp <= 0;
}

bool is_full(){
	return sp >= STACK_SIZE;
}

void push(int v){
	if (is_full()) {
		terminate("push: stack is full");		
	}
	stack[sp++] = v;
}

int pop(){
	if (is_empty()) {
		terminate("pop: stack is empty");
	}
	return stack[--sp];
}




