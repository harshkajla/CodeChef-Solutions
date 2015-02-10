#include<stdio.h>
#define mod 1000000007
typedef long long int ll;
int pos[100001];
bool marked[100001];
int maxpow[100001];
ll max(ll a, ll b)
{
    if(a>b)return a;
    return b;
}
ll lcm(ll a, ll b)
{
    int i;
    ll f1,f2,ans=1,ta=a;
    for(i=2;i*i<=ta;i++)
    {
        f1=1;
        while(a%i==0)
        {
            a/=i;
            f1*=i;
        }
        f2=1;
        while(b%i==0)
        {
            b/=i;
            f2*=i;
        }
        ans*=max(f1,f2);
        if(ans>mod)
        ans%=mod;
    }
    ans*=a;
    ans%=mod;
    ans*=b;
    ans%=mod;
    return ans;
}
void store(ll n)
{
    ll temp=n;
    int i,pow;
    for(i=2;i*i<=temp;i++)
    {
        if(n%i==0)
        {
            pow=0;
            while(n%i==0)
            {
                n/=i;
                pow++;
            }
            maxpow[i]=max(maxpow[i],pow);
        }
    }
    if(n!=1)//n is prime..
    maxpow[n]=max(maxpow[n],1);
}
int main()
{
    int t,i,n,j,count,nummarked;
    ll ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",pos+i);
            marked[i]=false;
            maxpow[i]=0;
        }
        nummarked=0;
        for(i=1;nummarked!=n;i++)
        {
            //pick up a bandit which is not in a discovered cycle..
            if(marked[i]==false)
            {
                nummarked++;
                marked[i]=true;
                j=pos[i];
                count=1;
                while(j!=i)
                {
                    nummarked++;
                    marked[j]=true;
                    j=pos[j];
                    count++;
                }
                store(count);
            }
        }
        ans=1;
        for(i=2;i<=n;i++)
        {
            while(maxpow[i])
            {
                ans*=i;
                maxpow[i]--;
                if(ans>mod)ans%=mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
