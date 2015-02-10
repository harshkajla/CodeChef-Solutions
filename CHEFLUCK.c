//codechef-CHEFLUCK
#include<stdio.h>
int main()
{int t,i=0;
long int n;
    scanf("%d",&t);
outer:
for(;i<t;i++)
{scanf("%ld",&n);
if(n%7==0)
{printf("%d\n",n);
continue;
}
else
{while(n>=0)
{n-=4;
if(n%7==0)
{printf("%d\n",n);
i+=1;
goto outer;}}}
printf("-1\n");
}return 0;
}
