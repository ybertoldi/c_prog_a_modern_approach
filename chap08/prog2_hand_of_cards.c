#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main() {
  const char *ranks[] = {"A", "2", "3",  "4", "5", "6", "7",
                         "8", "9", "10", "J", "Q", "K"};
  const char *suits[] = {"c", "d", "h", "s"};
  bool inhand[NUM_SUITS][NUM_RANKS] = {false};
  int n, handr, hands;

  printf("enter the number of cards in hand: ");
  scanf("%d", &n);

  printf("Your hand: ");
  while (--n > 0) {
    do {
      handr = random() % 13;
      hands = rand() % 4;
    } while (inhand[hands][handr]);

    printf("%s%s ", ranks[handr], suits[hands]);
  }
  printf("\n");

  return 0;
}
