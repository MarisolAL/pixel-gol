//#include <katsu/kt.h>
#include <time.h>

int size = 20;

int main() {
  srand(time(NULL));
  int board[size][size];

  for (int i =0; i<size; i++){
    for (int j = 0; j < size; j++){
      board[i][j] = 1;
    }
  }
  //populate_board(board);
  //iterate_board(board, 1);
}
