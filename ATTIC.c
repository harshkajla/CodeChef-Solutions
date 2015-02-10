//finding no of days required.
#include<stdio.h>
#include<string.h>
int main()
{long int t,i;
   long int dot,days,prevdot;
    long int j,len;
    //accepting t
    scanf("%ld",&t);
    
    char str[5000000];
    for(i=0;i<t;i++)
    {scanf("%s",&str);
len=strlen(str);
dot=0;days=0;
prevdot=0;
for(j=0;j<len;j++)
{
if(str[j]=='.')
dot++;
if(str[j+1]=='#')
{if(dot>prevdot)
{days++;prevdot=dot;}
dot=0;}
}printf("%d\n",days);
}
return 0;}
