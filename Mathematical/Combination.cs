using System;
					
public class Combination
{
	public static void Main()
	{
		Console.WriteLine("3C2 = " + nCr(3, 2));
		Console.WriteLine("4C2 = " + nCr(4, 2));
		Console.WriteLine("5C2 = " + nCr(5, 2));
	}
	
	private static int factorial(int n)
	{
		if (n <= 1)
        {
            return 1;
        }

		return n * factorial(n - 1);
	}
	
	private static int nCr(int n, int r)
	{
        // nCr = n!/(r!)*(n-r)!
		return factorial(n) / (factorial(r) * factorial(n - r)); 
	}
}