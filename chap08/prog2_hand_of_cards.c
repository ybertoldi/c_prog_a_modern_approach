#include <stdio.h>
#include <stdlib.h>

int main(){
  const char *ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
  const char *suits[] = {"c", "d", "h", "s"};
  int n;

  printf("enter the number of cards in hand: ");
  scanf("%d", &n);

  printf("Your hand: ");
  while (--n > 0) {
      int handr = random() % 13;
      int hands = rand() % 4;
      printf("%s%s ", ranks[handr], suits[hands]);
  }
  printf("\n");

  return 0;
}
