#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

static struct node *head = NULL;

static void terminate(const char* message){
	printf("%s", message);
	exit(EXIT_FAILURE);
}

void make_empty(){
	while (!is_empty()) {
		pop();
	}
}

bool is_empty(){
	return head == NULL;
}

bool is_full(){
	return false;
}

void push(int i){
	struct node *new_node = malloc(sizeof(struct node));
	new_node->val = i;
	new_node->next = head;
	head = new_node;
}

int pop(){
	struct node *todelete;
	int val;

	if (is_empty()) {
		terminate("pop: stack is empty");
	}

	todelete = head;
	val = todelete->val;
	head = head->next;
	free(todelete);

	return val;
}

