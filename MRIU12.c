#include<stdio.h>
#include<ctype.h>
long long int rev(long long int);
int main()
{
	int t,sum,i,r;
	long long int n;
	char code[10][6]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
	int dots[10]={0,1,2,3,4,5,4,3,2,1};
	scanf("%d",&t);
	while(t--)
	{sum=0;
		scanf("%lld",&n);
        n=rev(n);
		for(i=0;i<10;i++)
		{
		    r=n%10;n/=10;
			printf("%s",code[r]);
			sum+=dots[r];
		}
		printf("\n");
		printf("%d\n",sum);
}
	return 0;
}
long long int rev(long long int n)
{
    int r;long long int rev=0;
    while(n!=0)
    {
        r=n%10;n/=10;
        rev=rev*10+r;
    }
    return rev;
}
