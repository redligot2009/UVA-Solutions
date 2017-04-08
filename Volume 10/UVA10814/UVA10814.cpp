import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main
{
	//UVA 10814 - Simplifying fractions
	//Red Ligot 3/22/2017, 615th place
	public static void main (String[] args) throws java.lang.Exception
	{
		//Solution using BigInteger
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