#include<stdio.h>
int main()
{
	int t;
	long long int a,b;
	scanf("%d",&t);
	while(t--)
	{
		//a=candies
		//b=students
		scanf("%lld%lld",&a,&b);
		if(b==0)//candies per student, candies for teacher
		printf("0 %lld\n",a);
		else if(a==0)
			printf("0 0\n");
		else
		printf("%lld %lld\n",a/b,a%b);
	}
	return 0;
}
