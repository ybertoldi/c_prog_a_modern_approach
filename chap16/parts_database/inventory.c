#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_PARTS 100

char read_input();
void insert();
void search();
void update();
void print_inventory();
void save_inventory();
void load_inventory();

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
} inventory[MAX_PARTS];
int num_parts; /* number of parts currently stored */

int main() {
  load_inventory();
  for (;;) {
    char inp;
    printf("select operation: i - insert | s - search | u - update | p - print "
           "| q - quit\n");
    scanf(" %c", &inp);
    switch (inp) {
    case 'i':
      insert();
      break;
    case 's':
      search();
      break;
    case 'u':
      update();
      break;
    case 'p':
      print_inventory();
      break;
    case 'q':
      save_inventory();
      return 0;
      break;
    }

    printf("\n");
  }
}

int find_part(int number) {
  for (int i = 0; i < num_parts; i++) {
    if (inventory[i].number == number) {
      return i;
    }
  }
  return -1;
}

void insert() {
  int part_number;

  if (num_parts >= MAX_PARTS) {
    printf("db is full\n");
    return;
  }

  printf("Enter the part number: ");
  scanf("%d", &part_number);

  if (find_part(part_number) >= 0) {
    printf("part already exists");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("enter name: ");
  int q = read_line(inventory[num_parts].name, NAME_LEN);

  printf("enter quantity in hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

void search() {
  int num;
  printf("enter a part number: ");
  scanf("%d", &num);

  int i = find_part(num);
  if (i >= 0) {
    printf("name: %s | number: %d | on_hand: %d\n", inventory[i].name,
           inventory[i].number, inventory[i].on_hand);
  } else {
    printf("not found\n");
  }
}

void update() {
  int number, on_hand;

  printf("enter part number: ");
  scanf("%d", &number);

  int i = find_part(number);
  if (i >= 0) {
    printf("enter new quantity on hand: ");
    scanf("%d", &on_hand);
    inventory[i].on_hand = on_hand;
    printf("part updated! \n");
  } else {
    printf("part not found\n");
  }
}

void print_inventory() {
  for (int i = 0; i < num_parts; i++) {
    printf("name: %s | number: %d | on_hand: %d\n", inventory[i].name,
           inventory[i].number, inventory[i].on_hand);
  }
}

void save_inventory() {
  FILE *fptr = fopen("inventory_db.txt", "w");
  for (int i = 0; i < num_parts; i++) {
    fprintf(fptr, "%d|%s|%d\n", inventory[i].number, inventory[i].name,
            inventory[i].on_hand);
  }
  fclose(fptr);
}

void load_inventory() {
  FILE *fptr = fopen("inventory_db.txt", "r");
  enum {NUM, NAME, ON_HAND} state = NUM;
  char temp[30];
  int c;
  int i;

  if (fptr == NULL) {
    printf("couldn`t open file\n");
    return;
  }

  int j = 0;
  while (1) {
    i = 0;

    c = fgetc(fptr);
    while (c != '|' && c != '\n' && c != EOF) {
      temp[i++] = c;
      c = fgetc(fptr);
    }
    temp[i] = '\0';

    if (c == EOF) {
      fclose(fptr);
      return;
    }

    switch (state) {
    case NUM:
      inventory[num_parts].number = atoi(temp);
      state = NAME;
      break;
    case NAME:
      strcpy(inventory[num_parts].name, temp);
      state = ON_HAND;
      break;
    case ON_HAND:
      inventory[num_parts++].on_hand = atoi(temp);
      state = NUM;
      break;
    default:
      printf("something wrong happened");
      fclose(fptr);
      return;
    }
  }
}
