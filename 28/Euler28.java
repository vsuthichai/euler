
class Euler28
{
  public static void main(String[] args) {
    Euler28 e28 = new Euler28();
    System.out.println(e28.solve());
  }

  final int DIR_NORTH = 0;
  final int DIR_EAST = 1;
  final int DIR_SOUTH = 2;
  final int DIR_WEST = 3;

  int[][] spiral;
  int rows = 1001;
  int cols = 1001;

  public int solve() {
    spiral = new int[rows][];
    for (int i = 0; i < cols; i++) {
      spiral[i] = new int[cols];
    }

    int cells = rows * cols;
    int length = 1;
    int length_i = 0;
    int length_switch = 0;
    int x = rows / 2;
    int y = cols / 2;
    int dir = DIR_EAST;
    
    spiral[x][y] = 1;
    for (int i = 2; i <= cells; i++) {
      switch (dir) {
        case DIR_NORTH: x--; break;
        case DIR_EAST:  y++; break;
        case DIR_SOUTH: x++; break;
        case DIR_WEST:  y--; break;
      }

      spiral[x][y] = i;

      if (++length_i == length) {
        length_i = 0;
        if ((length_switch = length_switch ^ 1) == 0)
          ++length;
        switch (dir) {
          case DIR_NORTH: dir = DIR_EAST; break;
          case DIR_EAST: dir = DIR_SOUTH; break;
          case DIR_SOUTH: dir = DIR_WEST; break;
          case DIR_WEST: dir = DIR_NORTH; break;
        }
      }
    }

    //print_spiral();

    int sum = 0;
    for (int i = 0; i < rows; i++) {
      sum += spiral[i][i] + spiral[rows - i - 1][i];
    }

    return sum - 1;
  }

  public void print_spiral() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        System.out.printf("%2d ", spiral[i][j]);
      }
      System.out.println();
    }
    System.out.println();
  }
}

