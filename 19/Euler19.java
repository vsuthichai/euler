class MyDate
{
  int month;
  int date;
  int year;

  public MyDate(int mo, int date, int yr) {
    this.month = mo;
    this.date = date;
    this.year = yr;
  }
}

class Euler19
{
  public static void main(String[] args) {
    Euler19 e19 = new Euler19();
    System.out.println(e19.solve());
  }

  MyDate[][] calendar;
  int month = 0;
  int date = 0;
  int year = 0;
  int weeks = 366 * 101 / 7;
  
  public int solve() {
    int solution = 0;

    // 2d array, 366 days * 100 years / 7 days in a week
    calendar = new MyDate[weeks][7];

    // Initialize first week, Jan 1, 1900 is a Mon
    for (int i = 1; i < 7; i++) {
      calendar[0][i] = nextDate();
    }

    for (int i = 1; i < weeks; i++) {
      for (int j = 0; j < 7; j++) {
        calendar[i][j] = nextDate();
        if (j == 0 && calendar[i][j].date == 1 && calendar[i][j].year >= 1901 && calendar[i][j].year <= 2000) {
          //System.out.printf("%2d-%2d-%4d\n", calendar[i][j].month, calendar[i][j].date, calendar[i][j].year);
          solution++;
        }
        if (calendar[i][j].month == 1 && calendar[i][j].date == 1 && calendar[i][j].year == 2001) {
          //print_calendar();
          return solution;
        }
      }
    }

    return solution;
  }

  public MyDate nextDate() {
    // init iterator
    if (month == 0 && date == 0 && year == 0) {
      month = 1; date = 1; year = 1900;
      return new MyDate(month, date, year);
    }

    switch (month) {
      case 2:
        ++date;
        if (date == 29) {
          // not a leap year
          if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
            date = 1;
            month++;
          }
          // leap year ok.
          else {
          }
        }
        else if (date == 30) {
          date = 1;
          month++;
        }
        break;

      // 30 day months
      case 4:
      case 6:
      case 9:
      case 11:
        if (++date == 31) {
          date = 1;
          month++;
        }
        break;

      // 31 day months
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
        if (++date == 32) {
          ++month;
          date = 1;
        }
        break;

      case 12:
        if (++date == 32) {
          month = 1;
          date = 1;
          ++year;
        }
        break;
    }

    return new MyDate(month, date, year);
  }

  public void print_calendar() {
    for (int i = 0; i < weeks; i++) {
      for (int j = 0; j < 7; j++) {
        if (calendar[i][j] == null)
          System.out.printf("   null    ");
        else
          System.out.printf("%2d-%2d-%4d ", calendar[i][j].month, calendar[i][j].date, calendar[i][j].year);
      }
      System.out.println();
    }
  }
}


