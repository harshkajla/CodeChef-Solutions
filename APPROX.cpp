/*
 * approx.cpp
 *
 *  Created on: Dec 22, 2014
 *      Author: mb1994
 */
#include<bits/stdc++.h>
using namespace std;
int digits[1000001];
int main()
{
	int t,k;
	cin>>t;
	while(t--)
	{
		cin>>k;
		if(k==0)
			puts("3");
		else
		{
			int num=103993;
			int denom=33102;
			int i=0;
			while(i<=k)
			{
				int temp=num/denom;
				int rev=0;
				do
				{
					int r=temp%10;
					temp/=10;
					rev=rev*10+r;
				}while(temp);
				do
				{
					digits[i++]=rev%10;
					rev/=10;
				}while(rev);
				num%=denom;
				num*=10;
			}
			printf("3.");
			for(int i=1;i<=k;i++)
				printf("%d",digits[i]);
			puts("");
		}
	}
	return 0;
}
