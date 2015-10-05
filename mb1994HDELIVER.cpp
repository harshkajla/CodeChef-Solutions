#include <bits/stdc++.h>
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
typedef long long ll;
using namespace std;
int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
}
int a[1001];
int dp[1001][1111];
int maxor(int n, int k)
{
    int tmp=k;
    k=1023;
    
    memset(dp,false, sizeof dp);
    
    for(int i=1;i<=k;i++)
    dp[0][i]=false;
    
    for(int i=0;i<=n;i++)
    dp[i][0]=true;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            dp[i][j]=dp[i-1][j] || dp[i-1][j^a[i-1]];
        }
    }
    
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(dp[i][j])
            ans=max(ans,j^tmp);
        }
    }
    
    return ans;
}
int main()
{
    int t,n,k;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n>>k;
        
        for(int i=0;i<n;i++)
        cin>>a[i];
        
        cout<<maxor(n,k)<<endl;
    }
    
	return 0;
}
