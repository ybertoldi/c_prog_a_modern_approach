#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

char ranks[] = {'2', '3', '4', '5', '6', '7', '8',
                '9', 't', 'j', 'q', 'k', 'a'};
char suits[] = {'c', 'd', 'h', 's'};
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
bool straight, flush, four, three;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main() {
  read_cards();
  analyze_hand();
  print_result();
  return 0;
}

void read_cards() {
  int cards_to_read = NUM_CARDS;

  while (cards_to_read > 0) {
    char txt[90], r = 0, s = 0;
    bool could_read = false, valid_rank = false, valid_suit = false;
    int rank_i, suit_i;

    printf("Enter a card: ");
    scanf("%s\n", txt);

    for (int i = 0; txt[i] != '\0'; i++) {
      if (!isalnum(txt[i])) {
        continue;
      }
      if (r) {
        s = txt[i];
        could_read = true;
        break;
      } else {
        r = txt[i];
      }
    }
    if (!could_read) {
      printf("bad input; ");
      continue;
    }

    for (int i = 0; i < NUM_RANKS; i++) {
      if (r == ranks[i]) {
        rank_i = i;
        valid_rank = true;
        break;
      }
    }
    if (!valid_rank) {
      printf("invalid rank; ");
      continue;
    }

    for (int i = 0; i < NUM_SUITS; i++) {
      if (s == suits[i]) {
        suit_i = i;
        valid_suit = true;
        break;
      }
    }
    if (!valid_suit) {
      printf("invalid suit; ");
      continue;
    }

    num_in_rank[rank_i]++;
    num_in_suit[suit_i]++;
    cards_to_read--;
  }
}

void analyze_hand() {
  straight = false, flush = false, four = false, three = false;
  pairs = 0;
  bool last_was_valid = false;
  int consec = 0;

  for (int i = 0; i < NUM_RANKS; i++) {
    int n = num_in_rank[i];
    switch (n) {
    case 0:
      last_was_valid = false;
      break;
    case 1:
      if (last_was_valid) {
        consec += 1;
      } else {
        last_was_valid = true;
        consec = 1;
      }
      break;
    case 2:
      pairs++;
      break;
    case 3:
      three = true;
      break;
    case 4:
      four = true;
      break;
    }
  }
  if (consec == 5) {
    straight = true;
  }

  for (int i = 0; i < NUM_SUITS; i++) {
    if (num_in_suit[i] == 5) {
      flush = true;
    }
  }
}

void print_result() {
  if (straight && flush) {
    printf("straight flush");
  } else if (four) {
    printf("four of a kind");
  } else if (three && pairs > 0) {
    printf("Full House");
  } else if (flush) {
    printf("flush");
  } else if (straight) {
    printf("straight");
  } else if (three) {
    printf("three of a kind");
  } else if (pairs == 2) {
    printf("two pairs");
  } else if (pairs == 1) {
    printf("one pair");
  } else {
    printf("High Card");
  }
  printf("\n");
}
