#include<stdio.h>
#include<math.h>
int main()
{
    long int x;
    long int n,m,r,c,t,o,i,a,b,y,d,op,max;
    scanf("%ld",&x);
    while(x--)
    {
       scanf("%ld",&n);
       scanf("%ld",&m);
       scanf("%ld",&r);
       scanf("%ld",&c);
       scanf("%ld",&t);
       
       a=2*r-1;
       b=(m-c)*2+1;
       y=(n-r+1)*2;
       d=2*c;
       
       o=a;
       op=1;
       if(b<o){o=b;op=2;}
       if(y<o){o=y;op=3;}
       if(d<o){o=d;op=4;}
       switch(op)
       {
       	case 1:
       		max=o*o-1;
       		break;
       	case 2:
       		max=o*o+o-1;
       		break;
       	case 3:
       		max=o*o-1;
       		break;
       	case 4:
       		max=o*o+o-1;
       }
       if(t>max)t=max;
       o = sqrt(t+1);
       t=t-o*o+1;
       if(o%2==0)
       {
       	r+=o/2;
       	r--;
       	c+=o/2;
       	for(i=1;i<=t;i++)
       	{
       		if(i==1)r++;
       		else if(i<=o+1)c--;
       		else r--;
       	}
       }
       else
       {
       	r-=o/2;
       	c-=o/2;
       	for(i=1;i<=t;i++)
       	{
       		if(i==1)r--;
       		else if(i<=o+1)c++;
       		else r++;
       	}
       }
       printf("%ld %ld\n",r,c);
    }
return 0;
}
