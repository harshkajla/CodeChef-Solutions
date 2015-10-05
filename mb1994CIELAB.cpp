#include<bits/stdc++.h>
using namespace std;
 
const int mod = 747474747;
int points[6667][5];
bool visited[6667];
long long maxd[6666];
 
inline long long dist(int i, int j, int d)
{
    long long ans = 0, del;
    for(int k = 0; k < d; k++)
    {
        del = points[i][k] - points[j][k];
        ans += (del * del);
    }
    
    return ans;
}
long long mst(int n, int d)
{
    long long dis = 1;
    
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        maxd[i] = -1;
    }
    
    for(int i = 1; i < n; i++)
        maxd[i] = max(maxd[i], dist(0,i,d));
    
    int cnt = 1;
    visited[0] = true;
    
    while(cnt != n)
    {
       //finding max dist.
       long long mx = -1, pos = 0;
       for(int i = 0; i < n; i++)
       {
            if(!visited[i] && maxd[i] > mx)
            {
                mx = maxd[i];
                pos = i;
            }
       }
       
       if(mx == 0)
        return dis % mod;
        
        dis *= mx%mod;
        if(dis > mod)
            dis%=mod;
            
       visited[pos] = true;
       cnt++;
       
       for(int i = 0; i < n; i++)
            if(!visited[i]) maxd[i] = max(maxd[i], dist(pos, i, d));
    }
    
    return dis % mod;
}
 
int main()
{
    int t,n,d;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d",&n,&d);
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < d; j++)
                scanf("%d",&points[i][j]);
                
        printf("%lld\n",mst(n,d));
    }
    
    return 0;
}
