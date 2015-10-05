import java.util.Scanner;
class Main
{
    public static void main(String[] args)throws java.lang.Exception
    {
        int len, count, i;
        String s;char c;
        
        Scanner in = new Scanner(System.in);
        
        s=in.next();
        count=0;
        len=s.length();
        int done[]=new int[len];    //to mark which characters have already been selected.
        
        for(i=0;i<len;i++)
        {
            done[i]=0;
        }
        
        i=0;
        do{
            i=s.indexOf('C',i);
            if(i==-1)break;
                count+=findChef(s,i,len,done);
                i+=1;
            }while(true);
        
        
        System.out.println(count);
        
    }
    public static int findChef(String s, int index, int len, int[] done)
    {
    	int h,e,f,ind;
    	
    	   ind=index;
        	do{
        		h=s.indexOf('H', ind);        	if(h==-1)return 0;
        		ind=h+1;
        	}while(ind<=len && done[h]==1);
        	if(h==-1)return 0;
        	
        	ind=h;
        	do{
        		e=s.indexOf('E',ind);        	if(e==-1)return 0;
        		ind=e+1;
        	}while(ind<=len && done[e]==1);
        	
        	if(e==-1)return 0;
        	
        	ind=e;
        	
        	do{
        		f=s.indexOf('F',ind);        	if(f==-1)return 0;
        		ind=f+1;
        	}while(ind<=len && done[f]==1);
        	
        	if(f==-1)return 0;
        	
        	done[h]=1;done[e]=1;done[f]=1;
        	return 1;
        
    }
}
