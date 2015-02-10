import java.io.*;
import java.math.*;
public class Main
{
    
    public static void main(String[] args)throws java.lang.Exception
    {
        BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(stdin.readLine());
        int len,i,requiredPay,j;String s;
        int count[]=new int[58];
        char c;
        
        for(i=0;i<t;i++)
        {requiredPay=0;
        
        //initialising count[]
        for(j=0;j<58;j++)
            count[j]=0;
        
            
            s=new String(stdin.readLine());
            
            len=s.length();
            
            for(j=0;j<len;j++)
            {
                c=s.charAt(j);
            
                count[c-65]++;
            }
            
            for(j=0;j<58;j++)
            {
                requiredPay+=Math.ceil(count[j]/2.0);
            }
            
            System.out.println(requiredPay);
        }
    }
}
