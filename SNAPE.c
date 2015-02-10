#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
int main()
{
    int t,b,ls;
    double ans1,ans2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&b,&ls);
        ans1=b*b-ls*ls;
        if(b<ls)ans1=-ans1;
        ans1=sqrt(ans1+0.0);
        ans2=sqrt(b*b+ls*ls);
        printf("%.5lf %.5lf\n",ans1,ans2);
    }
	return 0;
}
