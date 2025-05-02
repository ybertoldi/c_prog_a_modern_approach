#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 30
#define WORDS_BUF_SIZE 80
#define CHARS_IN_LINE 40

#define REACHED_LINE_LIMIT 2
#define FOUND_EOF 3
#define TERMINATE 4
#define MAX_NEWLINES 500

#define BUFFER_SIZE 100

char *words[WORDS_BUF_SIZE];
int word_pos = 0;
int char_count = 0;
int status = 0;
int newline_count = 0;

char buf[BUFFER_SIZE];
int bp = 0;

int bget() {
  if (bp > 0)
    return buf[--bp];
  int c = getchar();
  return c;
}

void bstore(int c) {
  if (bp < BUFFER_SIZE) {
    buf[bp++] = c;
  } else {
    printf("ERROR: buf is full\n");
  }
}

void readword(char wrd[]) {
  int c;
  int i = 0;

  while ((c = bget()) == ' ' || c == '\t' || c == '\n')
    ;

  if (c == EOF) {
    status = FOUND_EOF;
    wrd[i] = '\0';
    return;
  }

  while (i < WORD_SIZE - 1 && (isalnum(c) || ispunct(c))) {
    wrd[i++] = c;
    c = bget();
    char_count++;
  }

  wrd[i] = '\0';
  if (c != EOF)
    bstore(c);
}

void readline() {
  int isNewLine = 0;
  char *wrd;

  while (!isNewLine && char_count < CHARS_IN_LINE &&
         word_pos < WORDS_BUF_SIZE - 1) {
    wrd = malloc(WORD_SIZE);
    readword(wrd);

    if (isNewLine) {
      free(wrd);
      if (status == FOUND_EOF)
        break;
    } else {
      words[word_pos++] = wrd;
    }
  }

  if (status == FOUND_EOF) {
    status = FOUND_EOF;
  } else {
    status = REACHED_LINE_LIMIT;
  }
}

void printline() {
  if (status == FOUND_EOF) {
    for (int i = 0; i < word_pos; i++) {
      printf("%s ", words[i]);
      free(words[i]);
    }
    printf("\n");
    word_pos = 0;
    char_count = 0;
  } else if (status == REACHED_LINE_LIMIT) {
    for (int i = 0; i < word_pos - 1; i++) {
      printf("%s ", words[i]);
      free(words[i]);
    }
    printf("\n");
    words[0] = words[word_pos - 1];
    word_pos = 1;
    char_count = strlen(words[0]);
  }
}

int main() {
  while (status != FOUND_EOF && status != TERMINATE) { // Changed || to &&
    readline();
    printline();
  }

  for (int i = 0; i < word_pos; i++) {
    free(words[i]);
  }

  return 0;
}
