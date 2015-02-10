#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
inline int inp()    			
    {
    int noRead=0;
    char p=getchar_unlocked();
    for(;p<33;){p=getchar_unlocked();};
    while(p>32)
    {
    noRead = (noRead << 3) + (noRead << 1) + (p - '0');
    p=getchar_unlocked();
    }
    return noRead;
    };
int main()
{
    int i,j;
    ll t,n,m,x,y,s;
    t=inp();
    while(t--){ n=inp();  m=inp();
                x=n/m;
                y=n%m;
                s=((m-1)*x*(x-1))/2;              
                s+=x*((m-1)/2);                   
                s+=(x*(x-1))/2;                  
                s+=x*y;
                if(y>m/2)      s+=y-(m/2);
                printf("%lld\n",s);
                }
    return 0;
}
