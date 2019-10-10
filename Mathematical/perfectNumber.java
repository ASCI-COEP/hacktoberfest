import java.lang.Math;

public class Main {

	public static void main(String[] args) {
		long num1 = 496L;
		boolean res1 = perfectNumber(num1);
		if(res1)
			System.out.println("The number " + num1 + " is perfect");
		else
			System.out.println("The number " + num1 + " is not perfect");
    long num2 = 2579L;
		boolean res2 = perfectNumber(num2);
		if(res2)
			System.out.println("The number " + num2 + " is perfect");
		else
			System.out.println("The number " + num2 + " is not perfect");
	}

	public static boolean perfectNumber(long n){
    long sum = 1L;//Sum of all divisors of n
		if(n%2 == 1)
      //Odd numbers must satisfy n > 2^(1500) which is way bigger than the maximum of a long type (2^64 - 1)
			return false;
		else {
      long i = 2L;
      while(i < Math.sqrt(n) && sum < n){
				if(n%i == 0){
					sum += i;
					if(n/i != i)//If the divisor is equals to the divider we dont want to include it twice
						sum += n/i;
				}
				i++;
			}
		}
    if(sum == n) return true;
    return false;
	}
}