#include <stdio.h>
#include <stdlib.h>


int main(){
  int *a;
  int n = 50;
  a = calloc(sizeof(int), n);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
}
