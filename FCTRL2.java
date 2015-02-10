import java.math.BigInteger;
import java.io.*;
class Main
{
	static BigInteger facts[]=new BigInteger[101];
	private static BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
	
	
	public static void main(String[] args) throws java.lang.Exception
	{
		
		int t,n,i;
		t=Integer.parseInt(stdin.readLine());
		
		for(i=0;i<101;i++)
		{facts[i]=BigInteger.ZERO;
		}
		facts[1]=BigInteger.ONE;
		while(t!=0)
		{
			n=Integer.parseInt(stdin.readLine());
			
			System.out.println(fact(n));
			t--;
		}
	}
	
	public static BigInteger fact(int n)
	{int i,pos=0;
	
	
	
		if(n==1)return BigInteger.ONE;
		
		for(i=n;i>=0;i--)
		{
			if(facts[i]!=BigInteger.ZERO)
			{pos=i;break;}
		}
		BigInteger f=facts[pos];
		
		while(pos<n)
		{
			f=f.multiply(BigInteger.valueOf(pos+1));
			pos++;
		}
		facts[pos]=f;
		return f;
	}
		}
