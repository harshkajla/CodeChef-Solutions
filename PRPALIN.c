#include<stdio.h>
#define TWO 2
#include<string.h>
#include<math.h>
int main()
{long int n,i,j,rev,temp;
int f,len,r;
char str[20];
    scanf("%ld",&n);
if(n==2)
{printf("%d",TWO);
return 0;
}
n=(n%2==0)?(n+1):n;
for(i=n;;i+=2)
{f=0;
temp=i;r=0;rev=0;
//converting to integer array.
while(temp!=0)
{r=temp%10;
temp/=10;
rev=rev*10+r;
}
if(rev!=i)
continue;
//check for prime now.
for(j=3;j<=(int)sqrt(i);j++)
{if(i%j==0)
{f=1;
break;
}}
if(f==1)//not prime
continue;
else
{printf("%ld\n",i);
break;
}
}
return 0;
}
