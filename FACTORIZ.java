import java.math.BigInteger;
import java.io.*;
 
public class Main{
 
	static boolean marked[]=new boolean[1000001];
	static long primes[]=new long[78498];
	public static void sieve()
	{
		int c=0;
		
		for(int i=0;i<1000001;i++)
			marked[i]=false;
		
		marked[0]=true;
		marked[1]=true;
		for(int i=2;i<=1000;i++)
		{
			if(marked[i]==false)//prime
			{
				for(int j=i*i;j<=1000000;j+=i)
				{
					marked[j]=true;
				}
				
				primes[c++]=i;
			}
		}
		
		for(int i=1001;i<=1000000;i++)
		{
			if(marked[i]==false)
				primes[c++]=i;
		}
	}
 
	public static void main(String[] args)throws IOException
	{
		BigInteger n,x;
		int l1,c;
		long num;
		long ans[]=new long[1000];
		BigInteger bans[]=new BigInteger[1000];
		String str;
		
		sieve();
 
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		
		int t=Integer.parseInt(stdin.readLine());
		
		for(int tt=0;tt<t;tt++)
		{
			str=stdin.readLine();l1=str.length();
			n=new BigInteger(str);
			c=0;
			
			if(l1<=180)
			{c=0;
			for(int i=0;i<10;i++)
			{
				x=new BigInteger(Long.toString(primes[i]));
				
				if(n.equals(BigInteger.ONE) || x.compareTo(n.divide(x))>0)
					break;
				
				while(n.mod(x).equals(BigInteger.ZERO))
				{
					bans[c++]=x;
					n=n.divide(x);
				}
			}
			
			
			if(n.equals(BigInteger.ONE)==false)
				System.out.println(c+1);
			
			else
				System.out.println(c);
			
			for(int i=0;i<c;i++)
				System.out.println(bans[i]);
			
			if(n.equals(BigInteger.ONE)==false)
				System.out.println(n);
	
			}
						
			else
			{
 
				c=0;
				for(int i=0;i<1800;i++)
				{
					x=new BigInteger(Long.toString(primes[i]));
					
					if(n.equals(BigInteger.ONE) || x.compareTo(n.divide(x))>0)
						break;
					
					while(n.mod(x).equals(BigInteger.ZERO))
					{
						bans[c++]=x;
						n=n.divide(x);
					}
				}
				
				
				if(n.equals(BigInteger.ONE)==false)
					System.out.println(c+1);
				
				else
					System.out.println(c);
				
				for(int i=0;i<c;i++)
					System.out.println(bans[i]);
				
				if(n.equals(BigInteger.ONE)==false)
					System.out.println(n);
			}
		}
	}
}
