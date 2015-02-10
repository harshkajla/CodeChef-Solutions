//codechef-HOLES
#include<stdio.h>
#include<string.h>
int main()
{int hole[]={1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};
int t,i,j,l,holes=0;
char str[100];
scanf("%d",&t);
for(i=0;i<t;i++)
{
scanf("%s",str);
l=strlen(str);
for(j=0;j<l;j++)
holes+=hole[str[j]-'A'];
printf("%d\n",holes);
holes=0;
}
return 0;
}
