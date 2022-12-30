#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int len;
  int *data;
} list;
// return a list of n numbers with
// increasing value from 1 to n but if n
// is less than 3, then it returns from
// 1 to 6 e.g:
//   explode(10)
// returns:
//   [1,2,3,4,5,6,7,8,9,10]
list explode(int n) {
  if (n < 3) {
    n = 6;
  }
  list r = {0, malloc(n * 4)};
  for (int i = 1; i <= n; i++) {
    r.data[r.len++] = i;
  }

  return r;
}

int main(void) {
  list r = explode(11);
  printf("[");
  for (int i = 0; i < r.len; i++) {
    printf("%d", r.data[i]);
    if (i != r.len - 1) {
      printf(" ");
    }
  }
  printf("]\n");
}
