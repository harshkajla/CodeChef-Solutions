#include <stdio.h>
int main() {
	short int t;
	int n;
	long int x;
	long long int result;
	
	scanf("%hd",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		result = (long long int)n*(n-1);
		result/=2;
		
		while(n--)
		scanf("%ld",&x);
		
		printf("%lld\n",result);
	}
	return 0;
}
