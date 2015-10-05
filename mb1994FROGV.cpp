#include<bits/stdc++.h>
using namespace std;
int votes[1000];
int ways=0;
int num_elected(int prev, int cur, int n)
{
    if(cur==n+1)
    {
        ways++;
        //find num of max numbers..
        int ans=0;
        int maxvote=*max_element(votes+1,votes+n+1);
        for(int i=1;i<=n;i++)
        {
            if(votes[i]==maxvote)ans++;
        }
        return ans;
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i==prev) continue;
        
        votes[i]++;
        ans+=num_elected(i,cur+1,n);
        votes[i]--;
    }
    return ans;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
       
        ways=0;
        for(int i=1;i<=n;i++)
            votes[i]=0;
            
        for(int i=1;i<=n;i++)
        {
            votes[i]++;
            ans+=num_elected(i,2,n);
            votes[i]--;
        }
        printf("%.6lf\n",ans/static_cast<double>(ways));
    }
}
