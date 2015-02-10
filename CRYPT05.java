import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.io.*;
public class Main
{
    public static void main(String[] args)throws IOException,NumberFormatException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        long n,i;
        
        while(true)
        {
            n=Long.parseLong(br.readLine());
            
            if(n==0)
            return;
            
            BigInteger a=new BigInteger("1");
            BigInteger b=new BigInteger("0");
            BigInteger c=new BigInteger("1");
            
            for(i=0;i<n;i++)
            {
                c=a.add(b);
                a=b;
                b=c;
            }
            
            System.out.println(c);
        }
    }
}
