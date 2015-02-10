#include<stdio.h>
int main()
{
int n,t,pos,i,freq[10001],number;
scanf("%d",&t);
while(t--)
{
memset(freq,0,sizeof(int)*10001);
scanf("%d",&n);
while(n--)
{scanf("%d",&number);
freq[number]+=1;
}
pos=0;
//finding max frequency
for(i=1;i<=10000;i++)
{if(freq[i]>freq[pos])
pos=i;
}
printf("%d %d\n",pos,freq[pos]);
}
return 0;
}
