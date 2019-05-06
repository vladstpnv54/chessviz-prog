#include <stdio.h>

char numbers[8] = {8, 7, 6, 5, 4, 3, 2, 1};
char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                   {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                   {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                   {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'}};

void printboard()
{
    int i, j;
    for (i = 0; i < 8; i++) {
        printf("%d ", numbers[i]);
        for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (i = 0; i < 8; i++)
        printf("%c ", i + 97);
    printf("\n");
}

int main()
{
    printboard();
return 0;
}
