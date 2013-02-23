#include <iostream>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

using namespace std;

int rows = 20;
int cols = 20;
int numbers = 4;
int high = 0;
int **grid;

void horizontal()
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols - numbers + 1; j++) {
      //cout << grid[i][j] << " " << grid[i][j + 1] << " " <<  grid[i][j + 2] << " " << grid[i][j + 3] << " ";
      //cout << grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3] << endl;
      high = MAX(grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3], high);
    }
  }
}


void vertical()
{
  for (int j = 0; j < cols; j++) {
    for (int i = 0; i < cols - numbers + 1; i++) {
      //cout << grid[i][j] << " " << grid[i + 1][j] << " " <<  grid[i + 2][j] << " " << grid[i + 3][j] << " ";
      //cout << grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j] << endl;
      high = MAX(grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j], high);
    }
  }
}


void diag_ltr()
{
  for (int i = 0; i < rows - numbers + 1; i++) {
    for (int j = 0; j < cols - numbers + 1; j++) {
      //cout << grid[i][j] << " " << grid[i + 1][j + 1] << " " <<  grid[i + 2][j + 2] << " " << grid[i + 3][j + 3] << " ";
      //cout << grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3] << endl;
      high = MAX(grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3], high);
    }
  }
}


void diag_rtl()
{
  for (int i = 0; i < rows - numbers + 1; i++) {
    for (int j = numbers - 1; j < cols; j++) {
      //cout << grid[i][j] << " " << grid[i + 1][j - 1] << " " <<  grid[i + 2][j - 2] << " " << grid[i + 3][j - 3] << " ";
      //cout << grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3] << endl;
      high = MAX(grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3], high);
    }
  }
}

int main(int argc, char *argv[])
{
  grid = new int*[rows];
  for (int i = 0; i < rows; i++) {
    grid[i] = new int[cols];
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> grid[i][j];
    }
  }
  horizontal();
  vertical();
  diag_ltr();
  diag_rtl();
  cout << high << endl;
}

