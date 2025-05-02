#include "word.h"
#include <stdio.h>

int read_char() {
  int c = getchar();

  if (c == '\n' || c == '\t') {
    return ' ';
  }
  return c;
}

void read_word(char *word, int len) {
  int c, i = 0;

  while ((c = read_char()) == ' ')
    ;

  while (c != ' ' && c != EOF) {
    if (i < len)
      word[i++] = c;
    c = read_char();
  }
  word[i] = '\0';
}
