//CODECHEF-FCTRL
//finding number of zeros in a factorial.
#include<stdio.h>
int findZeros(long int);
int main()
{long int t,i;
    scanf("%ld",&t);
    long int n;int z[t];
    
    for(i=0;i<t;i++)
    {scanf("%ld",&n);   
z[i]=findZeros(n);}
//printing
for(i=0;i<t;i++)
{
printf("%d\n",z[i]);
}
return 0;
}
//findZeros function..
int findZeros(long int n)
{int zero=0,five=5;
while(five<=n)
{zero+=n/five;
five*=5;
}
return zero;
}
