#include <stdio.h>
#include <stdlib.h>
typedef struct list {
  int len;
  int *data;
} list;

// returns the first element from a list
// or 1 if the list is empty, e.g.:
//   [2,3,2]
// returns:
//   2
int first(list x) {
  int f = 1;
  if (x.len > 0) {
    f = x.data[0];
  }
  return f;
}

int main(void) {
  list x = {
      .len = 10,
      .data = malloc(x.len * 4),
  };

  int n = 0;
  x.data[n++] = 1;
  x.data[n++] = 1;
  x.data[n++] = 2;
  x.data[n++] = 3;
  x.data[n++] = 3;
  x.data[n++] = 4;
  x.data[n++] = 1;
  x.data[n++] = 2;
  x.data[n++] = 7;
  x.data[n++] = 1;

  printf("%d\n", first(x));
}
