#include <iostream>
#include <stdio.h>

using namespace std;

const int rows = 21;
const int cols = 21;

int print_grid(long **grid)
{
  for (int i = 0 ; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%-11ld ", grid[i][j]);
    }
    cout << endl;
  }
}

int main(int argc, char *argv[])
{
  long** grid = new long*[rows];
  for (int i = 0; i < rows; i++) {
    grid[i] = new long[cols];
  }

  for (int i = 0; i < rows; i++) {
    grid[i][0] = 1;
  }
  for (int j = 0; j < cols; j++) {
    grid[0][j] = 1;
  }

  for (int i = 1; i < rows; i++) {
    for (int j = 1; j < cols; j++) {
      grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
    }
  }

  //print_grid(grid);
  cout << grid[rows - 1][cols - 1] << endl;
}
