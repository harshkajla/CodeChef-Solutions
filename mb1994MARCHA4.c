#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
char str[100001];
int main()
{
    int t,l,i;
    long long int ct;
    scanf("%d",&t);
    while(t--)
    {
        ct=0;
        scanf("%d",&l);
        getchar();
        scanf("%s",str);
        for(i=0;i<l;i++)
        {
            if(str[i]=='1')ct++;
        }
        printf("%lld\n",ct*(ct+1)/2);
    }
	return 0;
}
