#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	int t,n;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		cout<<unique(a,a+n)-a<<endl;
	}
	return 0;
}
