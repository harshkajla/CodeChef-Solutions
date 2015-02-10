import java.io.*;
public class Main
{
    
    public static void main(String[] args)throws java.lang.Exception
    {
        BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(stdin.readLine());
        long n;int i;
        for(i=0;i<t;i++)
        {
            n=Long.parseLong(stdin.readLine());
            
            System.out.println(n-n%2);
        }
    }
}
