
class Euler17
{
  public static String english(int i) {
    if (i < 10) {
      switch (i)
      {
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
      }
    }
    else if (i >= 10 && i < 20) {
      String strTens = null;
      switch (i)
      {
        case 10: return "ten";
        case 11: return "eleven";
        case 12: return "twelve";
        case 13: return "thirteen";
        case 14: return "fourteen";
        case 15: return "fifteen";
        case 16: return "sixteen";
        case 17: return "seventeen";
        case 18: return "eighteen";
        case 19: return "nineteen";
      }
      return strTens;
    } else if (i >= 20 && i < 100) {
      int tens = i / 10;
      String strTens = null;
      switch (tens)
      {
	case 2: strTens = "twenty"; break;
	case 3: strTens = "thirty"; break;
	case 4: strTens = "forty"; break;
	case 5: strTens = "fifty"; break;
	case 6: strTens = "sixty"; break;
	case 7: strTens = "seventy"; break;
	case 8: strTens = "eighty"; break;
	case 9: strTens = "ninety"; break;
      }
      return strTens + (i % 10 > 0 ? english(i % 10) : "");
    }
    else if (i >= 100 && i < 1000) {
      int hundreds = i / 100;
      String strHundreds = english(hundreds);
      int tens = i % 100;
      return strHundreds + "hundred" + (tens > 0 ? "and" + english(tens) : "");
    }
    else if (i >= 1000) {
      int thousands = i / 1000;
      String strThousands = english(thousands);
      return strThousands + "thousand";
    }

    return null;
  }

  public static void main(String[] args) {
    StringBuffer sb = new StringBuffer();
    for (int i = 1; i <= 1000; i++) {
      sb.append(english(i));
    }
    System.out.println(sb.length());
  }
}
