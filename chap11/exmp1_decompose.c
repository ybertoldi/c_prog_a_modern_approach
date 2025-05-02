#include <stdio.h>
void decompose(double x, long *int_part, double *frac_part) {
  *int_part = (long)x;
  *frac_part = x - *int_part;
}

int main() {
  double x = 3.14159;
  long i;
  double d;

  decompose(x, &i, &d);
  printf("integer part: %ld \n", i);
  printf("fractional part: %f", d);

  return 0;
}
