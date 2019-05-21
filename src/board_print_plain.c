#include "board_print_plain.h"
#include <stdio.h>

extern char desk[8][8];

void printdesk() {
  int i, j;
  for (i = 7; i >= 0; i--) {
    printf("%d ", i + 1);
    for (j = 0; j < 8; j++) {
      printf("%c ", desk[i][j]);
    }
    printf("\n");
  }
  printf("  ");
  for (i = 0; i < 8; i++)
    printf("%c ", i + 97);
  printf("\n");
}
