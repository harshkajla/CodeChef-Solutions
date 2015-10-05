#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int a[100001];
int l[100001];
int h[100001];
int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(int i=0;i<m;i++)
    {
        cin>>l[i];
    }
    
    //precomputing from back..
    dp[n-1]=1;h[a[n-1]]++;
    for(int i=n-2;i>=0;i--)
    {
        if(h[a[i]])
            dp[i]=dp[i+1];
        else dp[i]=dp[i+1]+1;
        h[a[i]]++;
    }
    
    for(int i=0;i<m;i++)
    {
        cout<<dp[l[i]-1]<<endl;
    }
}
