import java.math.BigInteger;
import java.util.Scanner;
class Main
{
    public static void main(String[] args)throws java.lang.Exception
    {
        int t,n,i,j,k,flag,forward,backward;
        char ch;
        String s;
        
        BigInteger a,b,c,precompute,premult;
        Scanner in = new Scanner(System.in);
        
        t=in.nextInt();
        
        for(i=0;i<t;i++)
        {
        	flag=0;
        	premult=new BigInteger("1");
        	
            n=in.nextInt();
            
            forward=0;
            backward=n-1;
            
            BigInteger list[] = new BigInteger[n];
            
            for(j=0;j<n;j++)
            {
                list[j]=new BigInteger(in.next());
            }
            
            a=new BigInteger(in.next());
            b=new BigInteger(in.next());
            c=new BigInteger(in.next());
            
            s=in.next();
            
            //initialising precomputed
            precompute = new BigInteger("0");
            
            //initialising count of 'M's appeared
            
            for(j=0;j<n;j++)
            {
                ch=s.charAt(j);
                
                if(ch=='A')
                {
                    precompute=precompute.add(a).mod(c);
                    if(flag==0)//will go right
                    {
                    	list[forward]=list[forward].multiply(premult).add(precompute).mod(c);
                    	System.out.print(list[forward]+" ");
                    	forward++;
                    }
                    else
                    {
                    	list[backward]=list[backward].multiply(premult).add(precompute).mod(c);
                    	System.out.print(list[backward]+" ");
                    	backward--;
                    }
                    
                }
                
                else if(ch=='M')
                {
                	precompute=precompute.multiply(b).mod(c);
                	premult=premult.multiply(b).mod(c);
                	
                	if(flag==0)//will go right
                    {
                    	list[forward]=list[forward].multiply(premult).add(precompute).mod(c);
                    	System.out.print(list[forward]+" ");
                    	forward++;
                    }
                    else
                    {
                    	list[backward]=list[backward].multiply(premult).add(precompute).mod(c);
                    	System.out.print(list[backward]+" ");
                    	backward--;
                    }
                    
                }
                
                else if(ch=='R')
                {
                	flag=(flag==0)?1:0;
                	
                	if(flag==0)//will go right
                    {
                    	list[forward]=list[forward].multiply(premult).add(precompute).mod(c);
                    	System.out.print(list[forward]+" ");
                    	forward++;
                    }
                	else
                    {
                    	list[backward]=list[backward].multiply(premult).add(precompute).mod(c);
                    	System.out.print(list[backward]+" ");
                    	backward--;
                    }
                		
                }
            }
            System.out.println();
        }
    }
}
