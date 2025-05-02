#include "line.h"
#include <stdio.h>
#include <string.h>

#define LINE_LEN 60

char line[LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

void clear_line() {
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word) {
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len + 1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining() { return LINE_LEN - line_len; }

void write_line() {
  int extraspaces, spaces_to_insert;
  extraspaces = LINE_LEN - line_len;

  for (int i = 0; i < line_len; i++) {
    if (line[i] != ' ') {
      putchar(line[i]);
    } else {
      spaces_to_insert = extraspaces / (num_words - 1);
      for (int j = 0; j <= spaces_to_insert; j++) {
        putchar(' ');
      }

      extraspaces -= spaces_to_insert;
      num_words--;
    }
  }
  putchar('\n');
}

void flush_line() {
  for (int i = 0; i < line_len; i++) {
    if (line[i] != '\0') {
      putchar(line[i]);
    }
  }
}
