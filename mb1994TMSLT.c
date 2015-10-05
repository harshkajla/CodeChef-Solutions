#include<stdio.h>
#define MOD 1000000007
void store(int n);
void reverse(int* a,int pos);
void findmod(unsigned long long int a);
int main()
{
    int t,n;
    unsigned long long int a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        store(n);
    }
    return 0;
}
void store(int n)
{int bin[20]={0};
    int i=0;
    while(n!=0)
    {
        bin[i++]=n%2;
        n/=2;
    }
    reverse(bin,i);
}
void reverse(int *a,int pos)
{unsigned long long int rev=0;
int i;
    for(i=pos-1;i>=0;i--)
    {
        rev=rev*10+a[i];
    }
    findmod(rev);
}
void findmod(unsigned long long int a)
{unsigned long long int a1=2;
unsigned long long int p=1;
int i=0;
while(a!=0)
{
     if (a&1)
      {
         p *= a1;
         p = p%MOD;
     }
     a/=2;
     a1=(a1*a1)%MOD;
}
p=(p*p)%MOD;
printf("%llu\n",p);
}
