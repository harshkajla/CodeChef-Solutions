#include<climits>
#include<limits.h>
#include<stdio.h>
typedef long long int ll;
ll best[101][101];
ll sum[101];
ll min(ll a, ll b)
{
    if(a<b)
    return a;
    return b;
}
ll csum(int l, int r)
{
    if(l==0)return sum[r]%100;
    return (sum[r]-sum[l-1])%100;
}
ll bestans(int l, int r)
{
    int i;
    if(l==r)
    {
        best[l][r]=0;
        return best[l][r];
    }
    else if(best[l][r]!=0)
    return best[l][r];
    best[l][r]=LLONG_MAX;
    for(i=l;i<r;i++)
    {
        best[l][r]=min(best[l][r],bestans(l,i)+bestans(i+1,r)+csum(l,i)*csum(i+1,r));
    }
    return best[l][r];
}
int main()
{
    int i,n,j, col[101];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&col[i]);
            sum[i]=col[i]+ ((i==0)?0:sum[i-1]);
        }
        printf("%lld\n",bestans(0,n-1));
        for(i=0;i<101;i++)
        for(j=0;j<101;j++)
        best[i][j]=0;
    }
}
