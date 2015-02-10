#include<stdio.h>
    #define mod 1000000007
    #define gtc getchar_unlocked()
    #define pc(x) putchar_unlocked(x)
    typedef long int ll;
    inline int mini(int a,int b)
    {
    if(a<=b)return a;
    return b;
    }
    inline int maxi(int a, int b)
    {
    if(a>=b)return a;
    return b;
    }
    inline void writeInt (ll n)
    {
        ll N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
    }
    inline int read_int()
    {
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
    };
    int twopow(int n)
    {
    /*ll a=2,ans=1;
    if(n==0)return 1;
    while(n)
    {
    if(n&1)ans=(ans*a);
    if(ans>mod)ans%=mod;
    a=(a*a);
    if(a>mod)a%=mod;
    n>>=1;*/
    ll ans=1;
    while(n--)
    {
        ans<<=1;if(ans>mod)ans%=mod;
    }
    return ans;
    }
    int main()
    {
    int count[101];ll dp[101][201];
    int t,p,n,x,i,j,J,m1,m2,min,max,a,b;
    ll ans;
    t=read_int();
    while(t--)
    {
    for(i=1;i<101;i++)
    {
        if(count[i]!=0)
    count[i]=0;
    for(j=0;j<201;j++)
    {
        if(dp[i][j]!=0)
    dp[i][j]=0;
    }
    }
    n=read_int();a=101;b=0;
    for(i=0;i<n;i++)
    {
    //accept a number..
    p=read_int();
    if(p<a)a=p;
    else if(p>b)b=p;
    //go to all possible previous numbers..
    dp[p][100]<<=1;
    dp[p][100]++;
    if(dp[p][100]>mod)
    dp[p][100]%=mod;
    min=p-1;max=p-100;
    m1=mini(min,max);
    m2=maxi(min,max);
    for(j=m1;j<=m2;j++)
    {
    if(j==0)continue;
    x=p-j;J=j+100;
    if(x<1||x>100)continue;
    //if dp[p+j][J]==0
    if(dp[x][J]==0)
    {
    if(count[x]==0)
    dp[p][J]+=0;
    else
    {
    dp[p][J]+=count[x];
    }
    if(dp[p][J]>mod)
    dp[p][J]%=mod;
    }
    //else case:
    else
    {
    dp[p][J]+=dp[x][J]+count[x];
    if(dp[p][J]>mod)
    dp[p][J]%=mod;
    }
    }
    count[p]++;
    }
    ans=1;
    for(i=a;i<=b;i++)
    {
    for(j=0;j<201;j++)
    {
    if(j==100)
    {
    //printf("dp[%lld][%lld]=%lld\n",i,j-100,dp[i][j]);
    ans+=dp[i][j];
    if(ans>mod)
    ans%=mod;
    }
    else
    {
    //printf("dp[%lld][%lld]=%lld\n",i,j-100,dp[i][j]);
    ans+=dp[i][j];
    if(ans>mod)
    ans%=mod;
    }
    }
    }
    //printf("%lld aps found..\n",ans);
    ans=twopow(n)-ans;
    while(ans<0)
    ans+=mod;
    if(ans>mod)ans%=mod;
    writeInt(ans);pc('\n');
    }
    return 0;
    }
