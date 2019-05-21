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
    // printf("Вроде никого нет, чтобы рубить?\n");
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
  case 'R':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if ((Y2 == Y1) && (checkX())) {
      return 1;
    }
    if ((X2 == X1) && (checkY())) {
      return 1;
    }
    break;
  case 'N':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if ((Y1 - Y2 == 2) && (X1 - X2 == 1)) {
      return 1;
    }
    if ((Y2 - Y1 == 2) && (X2 - X1 == 1)) {
      return 1;
    }
    if ((Y2 - Y1 == 2) && (X1 - X2 == 1)) {
      return 1;
    }
    if ((Y1 - Y2 == 2) && (X2 - X1 == 1)) {
      return 1;
    }
    if ((Y1 - Y2 == 1) && (X2 - X1 == 2)) {
      return 1;
    }
    if ((Y2 - Y1 == 1) && (X2 - X1 == 2)) {
      return 1;
    }
    if ((Y1 - Y2 == 1) && (X1 - X2 == 2)) {
      return 1;
    }
    if ((Y2 - Y1 == 1) && (X1 - X2 == 2)) {
      return 1;
    }
    break;
  case 'B':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if (checkD()) {
      return 1;
    }
    break;
  case 'K':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if ((Y1 - Y2 != 1) && (Y2 - Y1 != 1) &&
        ((X1 - X2 != 1) && (X2 - X1 != 1))) {
      break;
    } else {
      return 1;
    }
    break;
  case 'Q':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if (checkX() || checkY() || checkD()) {
      return 1;
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
  case 'r':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if ((Y2 == Y1) && (checkX())) {
      return 1;
    }
    if ((X2 == X1) && (checkY())) {
      return 1;
    }
    break;
  case 'n':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if ((Y1 - Y2 == 2) && (X1 - X2 == 1)) {
      return 1;
    }
    if ((Y2 - Y1 == 2) && (X2 - X1 == 1)) {
      return 1;
    }
    if ((Y2 - Y1 == 2) && (X1 - X2 == 1)) {
      return 1;
    }
    if ((Y1 - Y2 == 2) && (X2 - X1 == 1)) {
      return 1;
    }
    if ((Y1 - Y2 == 1) && (X2 - X1 == 2)) {
      return 1;
    }
    if ((Y2 - Y1 == 1) && (X2 - X1 == 2)) {
      return 1;
    }
    if ((Y1 - Y2 == 1) && (X1 - X2 == 2)) {
      return 1;
    }
    if ((Y2 - Y1 == 1) && (X1 - X2 == 2)) {
      return 1;
    }
    break;
  case 'b':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if (checkD()) {
      return 1;
    }
    break;
  case 'k':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if ((Y1 - Y2 != 1) && (Y2 - Y1 != 1) &&
        ((X1 - X2 != 1) && (X2 - X1 != 1))) {
      break;
    } else {
      return 1;
    }
  case 'q':
    if ((input[2] == '-') && (desk[Y2][X2] != ' ')) {
      printf("Вроде надо рубить?\n");
      break;
    }
    if (checkX() || checkY() || checkD()) {
      return 1;
    }
    break;
  }
  return 0;
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

int checkX() {
  int i, c1 = X1, c2 = X2;
  if (Y1 != Y2) {
    return 0;
  }
  if (X1 > X2) {
    c1 = X2;
    c2 = X1;
  }
  for (i = c1 + 1; i < c2; i++) {
    if ((desk[Y1][i] > 'a' && desk[Y1][i] < 's') ||
        (desk[Y1][i] > 'A' && desk[Y1][i] < 'S')) {
      return 0;
    }
  }
  return 1;
}

int checkD() {
  int i, j, c1 = Y2, c2 = Y1, ci, cj;
  if (((Y2 - Y1) != (X2 - X1)) && ((Y2 - Y1) != (X1 - X2))) {
    return 0;
  }
  if (Y2 > Y1) {
    c1 = Y1;
    c2 = Y2;
    ci = 1;
  } else {
    ci = -1;
  }
  if (X2 > X1) {
    cj = 1;
  } else {
    cj = -1;
  }
  i = Y1 + ci;
  j = X1 + cj;
  while ((i < c2) && (i > c1)) {
    if (((desk[i][j] > 'a') && (desk[i][j] < 's')) ||
        ((desk[i][j] > 'A') && (desk[i][j] < 'S'))) {
      return 0;
    }
    i += ci;
    j += cj;
  }
  return 1;
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
