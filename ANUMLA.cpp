#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, ll> present;
ll a[1<<20];
ll ans[1000];
ll cnt,n;
void markall(ll len)
{
    ll comb=1<<len,bitno,tmp,sum;
    for(ll i=0;i<comb;i++)
    {
        bitno=0;
        //in any combination there must be new number..
        //if(((tmp>>len)&1)==0)continue;
        tmp=i;
        if(((tmp>>(len-1))&1)==0)continue;
        sum=0;
        //printf("i=%lld\n",i);
        int flag=0;
        while(tmp)
        {
            if(tmp&1)
            {
                sum+=ans[bitno];
                //printf("adding %lld\n",ans[bitno]);
            }
            tmp>>=1;
            bitno++;
        }
        //printf("len=%lld sum=%lld\n",len,sum);
        //if(binary_search(a+cnt,a+n,sum))
            present[sum]--;
            //printf("len=%lld sum=%lld\n",len,sum);
    }
}
int main()
{
    ll t,m,x,tmp;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&x);
        present.clear();
        n=1<<x;
        for(ll i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            present[a[i]]++;
        }
        sort(a,a+n);
        if(x<=2)
        {
            for(int i=0;i<x;i++)
            {
                if(i==0)printf("%lld",a[i+1]);
                else printf("% lld",a[i+1]);
            }
            puts("");
            continue;
        }
        ans[0]=a[1];
        ans[1]=a[2];
        present[ans[0]]--;
        present[ans[1]]--;
        present[ans[0]+ans[1]]--;
        cnt=2;
        while(cnt!=x)
        {
            for(ll i=cnt;i<n-1;i++)
            {
                if(present[a[i+1]]>0)
                {
          //          printf("now added %lld\n",a[i+1]);
                    ans[cnt++]=a[i+1];
                    //present[a[i+1]]--;
                    break;
                }
            }
            if(cnt==x)break;
            markall(cnt);
        }
        for(int i=0;i<x;i++)
        {
            if(i==0)printf("%lld",ans[i]);
            else printf(" %lld",ans[i]);
        }
        puts("");
    }
    return 0;
}
