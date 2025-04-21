#include <stdbool.h>
#include <stdio.h>

int main() {
  bool nums[10] = {false};
  bool foundDup = false;
  int c;

  while ((c = getchar()) != '\n') {
    if (nums[c - '0'] == true) {
      foundDup = true;
      break;
    }
    nums[c - '0'] = true;
  }
	
	char *txt = (foundDup == true) ? "duplicate digits" : "no duplicate digits";
  printf("%s", txt);
  printf("\n");
  return 0;
}
