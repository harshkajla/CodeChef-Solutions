#include<stdio.h>
int main()
{long int a;
int n,k,r;
scanf("%ld%d%d",&a,&n,&k);
if(a==0||n==0)
{while(k--)
printf("0 ");
printf("\n");
return 0;
}
while(k--)
{r=a%(n+1);
a/=n+1;
printf("%d ",r);
}
printf("\n");
return 0;
}
