/*
 * rrmtrx2.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: mb1994
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int sum[m];
	for(int i=0;i<m;i++)
		sum[i]=0;
	int tmp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>tmp;
			sum[j]+=tmp;
		}
	}
	long long ans=1,mod=10000007;
	for(int i=0;i<m;i++)
	{
		if(sum[i]<0)sum[i]+=mod;
		ans*=sum[i];
		if(ans>mod)
			ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
