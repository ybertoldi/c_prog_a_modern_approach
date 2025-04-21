#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GR_SIZE 10
#define MAX_ATTEMPTS 200

int main() {
  char grid[GR_SIZE][GR_SIZE];
  int directios[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  int dl, dc, r;
  int cur_ln = 0, cur_col = 0;
  char cur_char = 'A';
  int attempts = 0;
  bool stuck_in_loop = false;
  srand(time(NULL));

  // intitialize grid to '.'
  for (int j = 0; j < GR_SIZE; j++) {
    for (int k = 0; k < GR_SIZE; k++) {
      grid[j][k] = '.';
    }
  }
  grid[cur_ln][cur_col] = cur_char++;

  while (cur_char <= 'Z') {
    if (attempts >= MAX_ATTEMPTS) {
      stuck_in_loop = true;
      break;
    }

    r = rand() % 4;
    dl = directios[r][0], dc = directios[r][1];
    int new_ln = cur_ln + dl;
    int new_col = cur_col + dc;

    if (new_ln >= GR_SIZE || new_col < 0 || new_ln >= GR_SIZE || new_ln < 0) {
      attempts++;
      continue;
    }
    if (grid[new_ln][new_col] != '.') {
      attempts++;
      continue;
    }

    attempts = 0;
    cur_ln = new_ln, cur_col = new_col;
    grid[cur_ln][cur_col] = cur_char++;
  }

  for (int j = 0; j < GR_SIZE; j++) {
    for (int k = 0; k < GR_SIZE; k++) {
      printf("%c ", grid[j][k]);
    }
    printf("\n");
  }
  if (stuck_in_loop) {
    printf("cursor got stuck in loop on %c\n", --cur_char);
  }

  return 0;
}
