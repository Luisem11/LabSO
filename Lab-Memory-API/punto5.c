#include <stdio.h>

int main() {
  int *data;
  data = malloc(100*sizeof(int));
  data[100] = 0;
  return 0;
}

