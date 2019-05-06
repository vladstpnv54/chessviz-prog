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
int chartoint(char input[7])
{
    if ((input[2] != '-') && (input[2] != 'x')) {
        return 0;
    }
    X1 = (int)input[0] - 'A';
    Y1 = (int)input[1] - '1';
    X2 = (int)input[3] - 'A';
    Y2 = (int)input[4] - '1';
    if ((input[2] == 'x') && (desk[Y2][X2] == ' ')) {
        printf("Вроде никого нет, чтобы рубить?\n");
        return 0;
    }
    if ((X2 < 8) && (X2 >= 0) && (Y2 >= 0) && (Y2 < 8) && (X1 >= 0) && (X1 < 8)
        && (Y1 >= 0) && (Y1 < 8))
        return 1;
    return 0;
}
