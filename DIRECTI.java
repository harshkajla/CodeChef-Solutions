import java.io.*;
import java.util.Scanner;
import java.lang.String;
public class Main {
	public static void main(String[] args)throws IOException
	{
		int i,n,j,t;
		String temp,append;
		
		Scanner in=new Scanner(System.in);
		
		t=in.nextInt();
		
		for(i=0;i<t;i++)
		{
			n=in.nextInt();
			
			String s[]=new String[n];
			temp=new String(in.nextLine());
			
			for(j=0;j<n;j++)
			{
				s[j]=in.nextLine();
			}
			
			append=s[n-1].substring(0,s[n-1].indexOf(' '));
			s[n-1]=new String(s[n-1].replace(append, "Begin"));
			
			if(append.equals("Left"))append=new String("Right");
			else append=new String("Left");
			
			for(j=n-2;j>=0;j--)
			{
				if(j==0){s[j]=new String(s[j].replace("Begin", append));break;}
				
				temp=new String(s[j].substring(0,s[j].indexOf(' ')));
				
				
				s[j]=s[j].replace(temp, append);
				append=new String(temp);
				
				if(append.equals("Left"))append=new String("Right");
				else append=new String("Left");
				
			}
			
			for(j=n-1;j>=0;j--)
				System.out.println(s[j]);
			
		}
	}
}
