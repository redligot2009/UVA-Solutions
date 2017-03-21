import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int T = 0;
		BigInteger a, b;
		char c;
		Scanner myScanner = new Scanner(System.in);
		T = myScanner.nextInt();
		for(int i = 0; i < T; i ++)
		{
			a = myScanner.nextBigInteger();
			c = myScanner.next().charAt(0);
			b = myScanner.nextBigInteger();
			BigInteger myGCD = a.gcd(b);
			//System.out.println(myGCD);
			a = a.divide(myGCD);
			b = b.divide(myGCD);
			System.out.println(a + " / " + b);
		}
	}
}