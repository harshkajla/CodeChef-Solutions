#include<bits/stdc++.h>
using namespace std;
vector<int> factors[1000001];
int a[100001],indexes[1000001];
bool marked[1000001];
void sieve()
{
    for(int i=2;i<=1000;i++)
    {
        if(!marked[i])
        {
            for(int j=i<<1;j<=1000000;j+=i)
            {
                marked[j]=true;
                factors[j].push_back(i);
            }
            factors[i].push_back(i);
        }
    }
    for(int i=1001;i<=1000000;i+=2)
    {
        if(!marked[i])
            factors[i].push_back(i);
    }
}
int main()
{
    int t,n,g,l,prime;
    
    //factorizing numbers..
    sieve();
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            for(int j=0;j<factors[a[i]].size();j++)
                indexes[factors[a[i]][j]]=-1;
        }
        
        g=a[0];l=1;
        for(int j=0;j<factors[a[0]].size();j++)
        {
            prime=factors[a[0]][j];
            indexes[prime]=0;
        }
        
        int ans=-1,occurence;
        for(int i=1;i<n;i++)
        {
            //there's some factor of a[i] which has occured before..
            //for each prime factor..find the last index at which it has occured before i..
            occurence=-1;
            for(int j=0;j<factors[a[i]].size();j++)
            {
                prime=factors[a[i]][j];
                if(indexes[prime]>occurence)
                    occurence=indexes[prime];
                indexes[prime]=i;
            }
            
            if(occurence<(i-l))
            {
                l++;
                if(l>ans)ans=l;
            }
            
            else
            {
                if(l>ans)ans=l;
                l=i-occurence;
            }
        }
        if(ans==-1)
        {
            if(l<=1)
               puts("-1");
            else printf("%d\n",l);
        }
        else cout<<(ans==1?-1:ans)<<endl;
    }
    return 0;
}
