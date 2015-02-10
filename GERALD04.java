/* package whatever; // don't place package name! */
import java.util.*;
import java.lang.*;
import java.io.*;
/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int t,h1,m1,h2,m2,tGF,tChef,tDist,i,p1,p2;
		float res1,res2;
		String s1,s2;
		
		Scanner in = new Scanner(System.in);
		
		t=in.nextInt();
		
		for(i=0;i<t;i++)
		{
			s1=in.next();
			s2=in.next();
			
			p1=s1.indexOf(":");
			p2=s2.indexOf(":");
			
			h1=Integer.parseInt(s1.substring(0,p1));
			m1=Integer.parseInt(s1.substring(p1+1));
			
			h2=Integer.parseInt(s2.substring(0,p2));
			m2=Integer.parseInt(s2.substring(p1+1));
			
			tChef=0;
			tGF=60*h1+m1;
			tGF-=60*h2+m2;
			
			tDist=in.nextInt();
			
			res1=tGF+tDist+0.0f;
			
			if(tGF>=2*tDist)
			{
				res2=tGF;
			}
			else if(tGF>tDist)
			{
				res2=(2*tDist+tGF)/2.0f;
			}
			else{
				res2=tDist+tGF/2.0f;
			}
			
			System.out.printf("%.1f %.1f\n",res1,res2);
			
		}
	}
}
