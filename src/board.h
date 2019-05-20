#ifndef BOARD_H
#define BOARD_H

void scanan();
int chartoint(char numbers[6]);
int white();
int black();
void move();
int checkY();
int checkX();
int checkD();
int checkWIn(int status);
void transformPawn();

#endif
