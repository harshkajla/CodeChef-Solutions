#include<stdio.h>
#define MOD 1000000007
int main()
{
    int t;long int n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        //calculating
        findmod(n);
        }
    return 0;
}
void findmod(long int b)
{unsigned long long int a1=2;
unsigned long long int p=1;
while(b>0)
{
     if (b&1)
      {
         p *= a1;
         p = p%MOD;
     }
     b/=2;
     a1=(a1*a1)%MOD;
}
printf("%llu\n",p-1);
}
