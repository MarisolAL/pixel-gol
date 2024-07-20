//#include <katsu/kt.h>
#include <stdio.h>

int size = 20;

int mod(int a, int b)
{
  int r = a % b;
  return r < 0 ? r + b : r;
}

int von_neumann_neighborhood(int agent_x, int agent_y, int board[][size]){
  int right_neighbor = board[mod((agent_x + 1), size)][agent_y];
  int left_neighbor = board[mod((agent_x - 1), size)][agent_y];
  int down_neighbor = board[agent_x][mod((agent_y - 1), size)];
  int top_neighbor = board[agent_x][mod((agent_y + 1), size)];
  return top_neighbor + down_neighbor + left_neighbor + right_neighbor;
}

int moore_neighborhood(int agent_x, int agent_y, int board[][size]) {
  int radius = 1; // TODO Generalize?
  int total_value = 0;
  int x_min = agent_x - radius;
  int x_max = agent_x + radius;
  int y_min = agent_y - radius;
  int y_max = agent_y + radius;
  //printf("x_min: %d | x_max: %d | y_min: %d | y_max: %d \n" , x_min, x_max, y_min, y_max);
  for (int i = x_min; i < x_max + 1; i++){
    for (int j = y_min; j < y_max + 1; j++){
      if (! ((i == agent_x) && (j == agent_y))){
	//printf("FOR i %d j %d | mod_i %d, mod_j %d | value: %d total_value: %d\n",i, j, mod(i, size), mod(j, size), board[mod(i, size)][mod(j, size)], total_value);
	total_value += board[mod(i, size)][mod(j, size)];
      }
    }
  }
  return total_value;
}

int main() {
  int board[size][size];

  for (int i =0; i<size; i++){
    for (int j = 0; j < size; j++){
      board[i][j] = 1;
    }
  }
  moore_neighborhood(15, 15, board);
  printf("%d \n", von_neumann_neighborhood(19, 19, board));
  return 0;
}
