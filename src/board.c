#include "board.h"
#include <stdio.h>
#include <string.h>

extern char input[7];
extern int X1, X2, Y1, Y2;
extern char desk[8][8];

void scanan(int flag) {
  while (1) {
    while (1) {
      fgets(input, 7, stdin);
      if (chartoint(input)) {
        break;
      }
      printf("Введите заново:");
    }
    if (flag == 1) {
      if (white() == 1) {
        break;
      } else {
        printf("Введите заново:");
      }
    }
    if (flag == 2) {
      if (black() == 1) {
        break;
      } else {
        printf("Введите заново:");
      }
    }
  }
}
