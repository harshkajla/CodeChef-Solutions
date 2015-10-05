/* package whatever; // don't place package name! */
import java.util.Scanner;
import java.lang.*;
import java.io.*;
/* Name of the class has to be "Main" only if the class is public. */
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int t,i;
		
		Scanner in = new Scanner(System.in);
		
		t=in.nextInt();
		String s[]=new String[t];
		
		for(i=0;i<t;i++)
		{
			s[i]=in.next();
			if(s[i].contains("010")||s[i].contains("101"))
			System.out.println("Good");
			else
			System.out.println("Bad");
		}
		
	}
}
