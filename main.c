#include <katsu/kt.h>
#include "gol.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int size = 20;

int main() {
  srand(time(NULL));
  int board[size][size];

  for (int i =0; i<size; i++){
    for (int j = 0; j < size; j++){
      board[i][j] = 1;
    }
  }
  printf("Si jala 1 \n %d %d %d %d \n", board[0][0], board[0][1], board[0][2], board[0][3]);
  populate_board(size, board);
  printf("Si jala 2 \n %d %d %d %d \n", board[0][0], board[0][1], board[0][2], board[0][3]);
  iterate_board(size, board, 1);
  printf("Si jala 3 \n %d %d %d %d \n", board[0][0], board[0][1], board[0][2], board[0][3]);
  return 0;
}
