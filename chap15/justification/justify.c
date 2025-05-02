#include "line.h"
#include "word.h"
#include <string.h>

#define WORD_LEN 40

int main() {
  char word[WORD_LEN + 2];
  int word_len;

  clear_line();
  for (;;) {
    read_word(word, WORD_LEN + 1);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line();
      return 0;
    }

    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }

    add_word(word);
  }
}
