import java.util.*;

class Euler10 {
  public static void main(String[] args) {
    ArrayList<Integer> al = primes_below(Integer.parseInt(args[0]));
    System.out.println(al);
    long sum = 0;
    for (int i : al) sum += i;
    System.out.println(sum);
  }

  public static ArrayList<Integer> primes_below(int x) {
    ArrayList<Integer> al = new ArrayList<Integer>();
    if (x <= 2)
      return al;

    al.add(2);
    int prime = 3;
    boolean isPrime;
    double sqrtx;
    while (prime < x) {
      isPrime = true;
      sqrtx = Math.sqrt(prime);
      for (int i : al) {
        if (i > sqrtx)
          break;
        if (prime % i == 0) {
          isPrime = false;
          break;
        }
      }
      if (isPrime) {
        al.add(prime);
      }
      prime += 2;
    }
    return al;
  }

  public static ArrayList<Integer> prime_factors(int x) {
    ArrayList<Integer> al = new ArrayList<Integer>();
    if (x % 2 == 0) {
      al.add(2);
      while (x % 2 == 0)
        x /= 2;
      if (x == 1)
        return al;
    }

    //System.out.println(x);

    int prime = 3;
    while (x != 1) {
      //System.out.println(x / prime);
      //System.out.println(x % prime);
      if (x % prime == 0) {
        al.add(prime);
        while (x % prime == 0)
          x /= prime;
      }
      prime += 2;
    }

    //return al.toArray(new int[0]);
    return al;
  }
}
