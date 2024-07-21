#include <stdio.h>
#include <stdlib.h>

const int LIVE = 1;
const int DEAD = 0;


int mod(int a, int b)
{
  int r = a % b;
  return r < 0 ? r + b : r;
}

int random_state(){
  int random_bool = rand() % 2;
  if (random_bool){
    return LIVE;
  }
  return DEAD;
}

void populate_board(int size, int board[][size]){
  // Randomly populates
  for (int i =0; i<size; i++){
    for (int j = 0; j < size; j++){
      board[i][j] = random_state();
    }
  }
}

int von_neumann_neighborhood(int size, int agent_x, int agent_y, int board[][size]){
  int right_neighbor = board[mod((agent_x + 1), size)][agent_y];
  int left_neighbor = board[mod((agent_x - 1), size)][agent_y];
  int down_neighbor = board[agent_x][mod((agent_y - 1), size)];
  int top_neighbor = board[agent_x][mod((agent_y + 1), size)];
  return top_neighbor + down_neighbor + left_neighbor + right_neighbor;
}

int moore_neighborhood(int size, int agent_x, int agent_y, int board[][size]) {
  int radius = 1;
  int total_value = 0;
  int x_min = agent_x - radius;
  int x_max = agent_x + radius;
  int y_min = agent_y - radius;
  int y_max = agent_y + radius;
  for (int i = x_min; i < x_max + 1; i++){
    for (int j = y_min; j < y_max + 1; j++){
      if (! ((i == agent_x) && (j == agent_y))){
	total_value += board[mod(i, size)][mod(j, size)];
      }
    }
  }
  return total_value;
}

// TODO Refactor
int calculate_next_state(int neighbors_sum, int cell_state, int size){
  if (cell_state == LIVE){
    if (neighbors_sum == 2 || neighbors_sum == 3){
      return LIVE;
    }
    return DEAD;
  } else if (neighbors_sum == 3) {
    return LIVE;
  }
  return DEAD;
}

// It has to use previous values to calculate the next iteration
// Calculate neighborhoods, stores it in a array, updates the board and deletes de aux array
// when bMoore is 1, then uses moore neighborhoods
void iterate_board(int size, int board[][size], int bMoore){
  int* all_neighborhoods = malloc((size * size) * sizeof(int));
  for (int i =0; i<size; i++){
    for (int j = 0; j < size; j++){
      if (bMoore){
	all_neighborhoods[i * size + j] = moore_neighborhood(size, i, j, board);
      } else {
	all_neighborhoods[i * size + j] = von_neumann_neighborhood(size, i, j, board);
      }
    }
  }
  for (int i =0; i<size; i++){
    for (int j = 0; j < size; j++){
      board[i][j] = calculate_next_state(size, all_neighborhoods[i * size + j], board[i][j]);
    }
  }
  free(all_neighborhoods);
}
