import java.util.*;

class Euler8
{
  public static void main(String[] args) {
    //Scanner sc = null;
    try { 
      //sc = new Scanner(System.in);
      int[] array = new int[1000];
      for (int i = 0; i < 1000; i++) {
        array[i] = Character.digit((char) System.in.read(), 10);
        //System.out.print(array[i]);
      }
      int highestProd = 0;
      for (int i = 0; i <= 995; i++) {
        int prod = array[i] * array[i + 1] * array[i + 2] * array[i + 3] * array[i + 4];
        highestProd = Math.max(highestProd, prod);
        //System.out.println(prod);
      }
      System.out.println(highestProd);
    } catch (Exception e) {
    }
  }
}
