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

int chartoint(char input[7]) {
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
  if ((X2 < 8) && (X2 >= 0) && (Y2 >= 0) && (Y2 < 8) && (X1 >= 0) && (X1 < 8) &&
      (Y1 >= 0) && (Y1 < 8))
    return 1;
  return 0;
}

int white() {
  if ((desk[Y2][X2] > 'A') && (desk[Y2][X2] < 'S')) {
    return 0; //не рубим своих
  }
  switch (desk[Y1][X1]) {
  case 'P':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if ((desk[Y2][X2] == ' ') && (Y1 == 1) && (X1 == X2) && (Y2 - Y1 > 0) &&
        (Y2 - Y1 < 3) && checkY()) {
      return 1; //начальный ход
    }
    if ((desk[Y2][X2] == ' ') && (X2 == X1) && (Y2 - Y1 == 1)) {
      transformPawn();
      return 1; //ход по пустым клеткам
    }
    if ((desk[Y2][X2] < 's' && desk[Y2][X2] > 'a') &&
        ((X2 - X1 == 1) || (X2 - X1 == -1)) && (Y2 - Y1 == 1) &&
        (input[2] == 'x')) {
      return 1; //рубим чужих
    }
    break;
  }
  return 0;
}

int black() {
  if ((desk[Y2][X2] > 'a') && (desk[Y2][X2] < 's')) {
    return 0; //не рубим своих
  }
  switch (desk[Y1][X1]) {
  case 'p':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if ((desk[Y2][X2] == ' ') && (Y1 == 6) && (X1 == X2) && (Y1 - Y2 > 0) &&
        (Y1 - Y2 < 3) && checkY()) {
      return 1; //начальный ход
    }
    if ((desk[Y2][X2] == ' ') && (X2 == X1) && (Y1 - Y2 == 1)) {
      transformPawn();
      return 1; //ход по пустым клеткам
    }
    if ((desk[Y2][X2] < 'S' && desk[Y2][X2] > 'A') &&
        ((X1 - X2 == 1) || (X1 - X2 == -1)) && (Y1 - Y2 == 1)) {
      return 1; //рубим чужих
    }
    break;
    return 0;
  }
  return 0;
}

void transformPawn() {
  char npawn;
  if ((desk[Y1][X1] == 'p') && (Y2 == 0)) {
    while (1) {
      printf("Введите в какую фигуру вревратить:");
      npawn = getchar();
      if ((npawn == 'r') || (npawn == 'n') || (npawn == 'b') ||
          (npawn == 'q')) {
        desk[Y1][X1] = npawn;
        break;
      } else {
        printf("Введите правильную фигуру.\n");
      }
    }
  }
  if ((desk[Y1][X1] == 'P') && (Y2 == 7)) {
    while (1) {
      printf("Введите в какую фигуру вревратить:");
      npawn = getchar();
      if ((npawn == 'R') || (npawn == 'N') || (npawn == 'B') ||
          (npawn == 'Q')) {
        desk[Y1][X1] = npawn;
        break;
      } else {
        printf("Введите правильную фигуру.\n");
      }
    }
  }
}

void move() {
  desk[Y2][X2] = desk[Y1][X1];
  desk[Y1][X1] = ' ';
}

int checkY() {
  int i, c1 = Y1, c2 = Y2;
  if (X1 != X2) {
    return 0;
  }
  if (Y1 > Y2) {
    c1 = Y2;
    c2 = Y1;
  }
  for (i = c1 + 1; i < c2; i++) {
    if ((desk[i][X1] > 'a' && desk[i][X1] < 's') ||
        (desk[i][X1] > 'A' && desk[i][X1] < 'S')) {
      return 0;
    }
  }
  return 1;
}

int checkWIn(int status) {
  int i, j, player = 0;
  if (status == 1) {
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (desk[i][j] == 'q') {
          player = 1;
        }
      }
    }
  }
  if (status == 2) {
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (desk[i][j] == 'Q') {
          player = 2;
        }
      }
    }
  }

  if (player == 0) {
    return status;
  }

  return 0;
}
