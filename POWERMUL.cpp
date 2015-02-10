#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>
#define gtc getchar_unlocked()
#define pc(x) putchar_unlocked(x);
using namespace std;
int powers[100001];
bool marked[100001];
vector<pair<int, int> > factors[100001];
int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
}
inline long long modpow(long long a, long long b, int m)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        ans=(ans*a)%m;
        
        a=(a*a)%m;
        b>>=1;
    }
    
    return ans;
}
void sieve()
{
    int pow,temp;
    marked[0]=marked[1]=true;
    
    for(int i=2;i<=316;i++)
    {
        if(!marked[i])
        {
            factors[i].push_back(make_pair(i,i));
            for(int j=i<<1;j<=100000;j+=i)
            {
                pow=0;temp=j;
                while(temp%i==0)
                {
                    temp/=i;
                    pow++;
                }
                
                factors[j].push_back(make_pair(i,pow*j));
                marked[j]=true;
            }
        }
    }
    
    for(int i=317;i<=100000;i+=2)
    if(!marked[i])factors[i].push_back(make_pair(i,i));
}
int primes[100001];
int visited1[100001],visited2[100001];
vector<int> total;
int main()
{
    int t,n,m,q,r,pfactor,pow;
    long long ans;
    
    sieve();
    
    t=read_int();
    
    while(t--)
    {   
        n=read_int();
        m=read_int();
        q=read_int();
        
        while(q--)
        {
            r=read_int();
            
            total.clear();
            r=max(r,n-r);
            
            for(int i=r+1;i<=n;i++)
            {
                //printf("i=%d\n",i);
                //traverse through all primes of i.
                for(int j=0;j<factors[i].size();j++)
                {
                    pfactor = factors[i][j].first;
                    pow = factors[i][j].second;
                 
                    //printf("for i=%d prime=%d pow=%d\n",i,pfactor,pow);
                    if(visited1[pfactor]==t+1 && visited2[pfactor]==q+1)
                    primes[pfactor]+=pow;
                    
                    else
                    {
                        visited1[pfactor]=t+1;
                        visited2[pfactor]=q+1;
                        primes[pfactor]=pow;
                        total.push_back(pfactor);
                    }
                }
                
                for(int j=0;j<factors[i-r].size();j++)
                {
                    pfactor = factors[i-r][j].first;
                    pow = factors[i-r][j].second;
                    
                    //printf("for i=%d prime=%d pow=%d\n",i-r,pfactor,pow);
                    if(visited1[pfactor]==t+1 && visited2[pfactor]==q+1)
                    primes[pfactor]-=pow;
                    
                    else
                    {
                        visited1[pfactor]=t+1;
                        visited2[pfactor]=q+1;
                        
                        primes[pfactor]=-pow;
                        total.push_back(pfactor);
                    }
                }
            }
            
            ans=1;
            for(int i=0;i<total.size();i++)
            {
                pfactor=total[i];
                ans=(ans*modpow(pfactor,primes[pfactor],m));
                
                if(ans>m)
                ans%=m;
            }
            
            printf("%lld\n",ans);
        }
    }
    
    return 0;
}
