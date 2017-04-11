/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
        String line;
 
        public FastReader()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
        
        BigInteger nextBigInteger()
        {
        	BigInteger retValue = new BigInteger(next());
        	return retValue;
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
        
        public boolean hasNext() throws Exception
    	{
	        if ( st == null || !st.hasMoreTokens() )
	        {
	            line = br.readLine();
	            if ( line != null )
	            {
	                st = new StringTokenizer(line.trim());
	                return hasNext();
	            }
	            else
	            {
	                return false;
	            }
	        }
	        return true;
    	}
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		FastReader myScanner = new FastReader();
		BigInteger[] dp = new BigInteger[1001];
		dp[0] = BigInteger.valueOf(1);
		dp[1] = BigInteger.valueOf(1);
		dp[2] = BigInteger.valueOf(2);
		for(int i = 3; i <= 1000; i ++)
		{
			dp[i] = dp[i-1].multiply(BigInteger.valueOf(i));
		}
		while(myScanner.hasNext())
		{
			int toFactorial = myScanner.nextInt();
			System.out.print(toFactorial);
			System.out.println("!");
			System.out.println(dp[toFactorial]);
		}
	}
}