import java.io.*;
import java.util.*;
import java.lang.String;
class Main
{
    public static void main(String[] args)
    {
        int i,j,k,mlen,wlen,biglen;
        String temp,m,w;
        
        Scanner in=new Scanner(System.in);
        int t = in.nextInt();
        
        for(i=0;i<t;i++)
        {
            
            m=in.next();
            w=in.next();
            
            mlen=m.length();
            wlen=w.length();
            biglen=mlen;
            
            if(mlen<wlen)
            {
                biglen=wlen;
                
                temp=m;
                m=w;
                w=temp;
            }
            k=0;
            mlen=m.length();
            wlen=w.length();
            
            for(j=0;j<biglen;j++)
            {
                if(m.charAt(j)==w.charAt(k))
                {
                    k++;
                }
                if(k==wlen)break;
            }
            
            if(k==wlen)
            System.out.println("YES");
            
            else
            System.out.println("NO");
            
        }
    }
}
