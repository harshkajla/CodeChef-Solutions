using System;
public class Test
{
	public static void Main()
	{
		// your code goes here
		while(true)
		{
			int n = Convert.ToInt32(Console.ReadLine());
			if(n==42)
				break;
				
			Console.WriteLine(n);
		}
	}
}
