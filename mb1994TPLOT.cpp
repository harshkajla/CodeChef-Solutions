#include<bits/stdc++.h>
#define lol long long
using namespace std;
int parent[200001];
int a[200001];
int dp[200001][201];
int mini[200001][201];
int findconnect[201][201];
int findp(int x)
{
    if(parent[x]==x)
        return x;
        
    parent[x]=findp(parent[x]);
    return parent[x];
}
void connect(int x, int y)
{
    int px=findp(x);
    int py=findp(y);
    parent[px]=py;
}
bool connected(int x, int y)
{
    if(findconnect[x][y]!=-1)
        return findconnect[x][y];
        
    return findconnect[x][y]=findconnect[y][x]=(findp(x)==findp(y));
}
int main()
{
    int t,m,k,n,x,y,f,res;
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&m,&k,&n);
        
        for(int i=0;i<=m;i++) parent[i]=i;
        
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&x,&y);
            connect(x,y);
        }
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        
        for(int i=0;i<n;i++)
            mini[i][0]=dp[i][0]=INT_MAX;
            
        for(int i=0;i<=m;i++)
            for(int j=0;j<=m;j++)
                findconnect[i][j]=-1;
                
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==0)
                {
                    if(a[0]==j)
                        dp[i][j]=0;
                        
                    else dp[i][j]=connected(a[0],j)?1:n+1;
                    
                    mini[i][j]=min(mini[i][j-1],dp[i][j]);
                }
                
                else
                {
                    //what will be the cost if a[i] were=j?
                    //it will be the min of dp[i-1][1], dp[i-1][2], ....., dp[i-1][j].
                    if(!connected(a[i],j))
                    {
                        dp[i][j]=n+1;
                        
                        mini[i][j]=min(mini[i][j-1],dp[i][j]);
                        
                        continue;
                    }
                    
                    dp[i][j]=mini[i-1][j]+(a[i]!=j);
                    mini[i][j]=min(mini[i][j-1],dp[i][j]);
                }
            }
        }
        
        int ans=mini[n-1][m];
        if(ans>=n)
            printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
