#include<stdio.h>
#include<algorithm>
#include<math.h>
#define mod 1000000007
#define gtc getchar_unlocked()
using namespace std;
typedef long long int ll;
ll sum[10001];
ll a[10001];
ll pows[62][31624];
inline long long int lread_int()
{
    register long long int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
//problm most prob in j=2 n 3
/*
inline ll findfloor(ll x, ll pow)
{
    ll index;
    if(pow==3)
    {
        index=lower_bound(pow3,pow3+31624,x)-pow3;
        if(pow3[index]>x)index--;
        return index;
    }
}*/
inline ll multmod(ll a, ll b)
{
    return (a*b)%mod;/*
    ll ans=0;
    while(b)
    {
        if(b&1)ans=(ans+a)%mod;
        a=(a<<1)%mod;
        b>>=1;
    }*/
    //return ans%mod;
}
int main()
{
    int t,n,q,i,j,index;
    ll ans,x;
    for(i=0;i<31624;i++){pows[0][i]=1;}
    for(i=0;i<62;i++){pows[i][0]=0;}
    for(i=1;i<62;i++)
    {
        for(j=1;j<31624;j++)
        {
            pows[i][j]=pows[i-1][j]*j;
            if(pows[i][j]>1000000000000000000 || pows[i][j]<0)
            {
                pows[i][j]=1000000000000000001;
            }
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            a[i]=lread_int();
            sum[i]=(sum[i-1]+a[i])%mod;
        }
        for(i=0;i<q;i++)
        {
            x=lread_int();
            ans=0;
            for(j=1;j<=n;j++)
            {
                //finding floor(pow(x,1.0/j))
                if(j==1)ans+=multmod(a[j],x%mod);
                else if(j==2)
                {
                    ans+=multmod(a[j],(ll)floor(sqrt(x+0.0d)));
                    ans%=mod;
                }
                else if(j==3)
                {
                    ans+=multmod(a[j],(ll)floor(cbrt(x+0.0d)));
                    ans%=mod;
                    continue;
                }
                else
                {
                    index=lower_bound(pows[j],pows[j]+31624,x)-pows[j];
                    //adjusting lower bound..
                    while(pows[j][index]>x)
                    index--;
                    if(index==1)
                    {
                        ans+=(sum[n]-sum[j-1])%mod;
                        ans%=mod;
                        break;
                    }
                    else
                    {
                        ans+=multmod(a[j],index);
                        ans%=mod;
                    }
                }
            }
            while(ans<0)ans+=mod;
            printf("%lld ",ans%mod);
        }
        printf("\n");
    }
    return 0;
}
