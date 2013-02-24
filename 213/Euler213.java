import java.util.*;

class Square
{
  LinkedList<Flea> ll = new LinkedList<Flea>();
}

class Flea
{
  int x;
  int y;
}

class Euler213
{
  static LinkedList<Flea> ll = new LinkedList<Flea>();
  final static int NORTH = 0;
  final static int SOUTH = 1;
  final static int WEST = 2;
  final static int EAST = 3;
  static Random r = new Random();
  static Square[][] grid;
  static long total_experiments = 21000000;

  public static void main(String[] args) {
    init_grid();
    int unoccupied = 0;
    for (int i = 0; i < total_experiments; i++) {
      clear();
      unoccupied += experiment();
    }
    System.out.printf("%.7f\n", (double)unoccupied / total_experiments);
  }

  public static void init_grid() {
    grid = new Square[30][];
    for (int i = 0; i < 30; i++) {
      grid[i] = new Square[30];
      for (int j = 0; j < 30; j++) {
        grid[i][j] = new Square();
      }
    }
  }

  public static void clear() {
    ll.clear();
    for (int x = 0; x < 30; x++) {
      for (int y = 0; y < 30; y++) {
        grid[x][y].ll.clear();
      }
    }
  }

  public static long experiment() {
    for (int x = 0; x < 30; x++) {
      for (int y = 0; y < 30; y++) {
        Flea f = new Flea();
        f.x = x;
        f.y = y;
        ll.add(f);
      }
    }

    for (int i = 0; i < 50; i++) {
      for (Flea f : ll) {
        randomize(f);
      }
    }

    for (Flea f : ll) {
      grid[f.x][f.y].ll.add(f);
    }

    int unoccupied = 0;

    for (int x = 0; x < 30; x++) {
      for (int y = 0; y < 30; y++) {
        if (grid[x][y].ll.isEmpty())
          unoccupied++;
      }
    }
    //System.out.println(unoccupied);
    return unoccupied;
  }

  public static void randomize(Flea f) {
    boolean done = false;
    while (!done) {
      int dir = r.nextInt(4);
      switch (dir) {
        case NORTH:
          if (f.y + 1 <= 29) {
            f.y += 1;
            done = true;
          }
          break;
        case SOUTH:
          if (f.y - 1 >= 0) {
            f.y -= 1;
            done = true;
          }
          break;
        case WEST:
          if (f.x + 1 <= 29) {
            f.x += 1;
            done = true;
          }
          break;
        case EAST:
          if (f.x - 1 >= 0) {
            f.x -= 1;
            done = true;
          }
          break;
      }
    }
  }
}
