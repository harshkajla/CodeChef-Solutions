/*
 * rrjoke.cpp
 *
 *  Created on: Dec 21, 2014
 *      Author: mb1994
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,x,y,N;
	cin>>t;
	while(t--)
	{
		cin>>N;
		int ans=0;
		for(int i=0;i<N;i++)
		{
			cin>>x>>y;
			ans=ans^(i+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
