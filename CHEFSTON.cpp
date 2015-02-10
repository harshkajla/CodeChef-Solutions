#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001];
int main()
{
    int t;
    long long n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long profit = (k/a[i])*b[i];
            ans = max(ans, profit);
        }
        cout<<ans<<endl;
    }
    return 0;
}
