#include "readline.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int main() {
  char *reminders[MAX_REMIND];
  char day_str[3], msg_str[MSG_LEN + 1];
  int day, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("- out of space \n");
      break;
    }

    printf("enter day and reminder : ");
    scanf("%2d", &day);
    if (day == 0)
      break;

    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++) {
      if (strcmp(day_str, reminders[i]) < 0)
        break;
    }

    for (j = num_remind; j > i; i--)
      reminders[j] = reminders[j - 1];

    reminders[i] = malloc(2 + strlen(msg_str) + 1);

    if (reminders[i] == NULL) {
      printf("- no space left - \n");
      break;
    }

    strcpy(reminders[i], day_str);
    strcat(reminders[i], msg_str);
    num_remind++;
  }
  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s \n", reminders[i]);
  return 0;
}
