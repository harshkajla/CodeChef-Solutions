#include<bits/stdc++.h>
using namespace std;
int w[21];
bool subsetSum(int sum, int i, int n)
{
    if(sum == 0)
        return true;
        
    else if(sum < 0 || i>=n)
        return false;
        
    return subsetSum(sum-w[i],i+1,n) || subsetSum(sum,i+1,n);
}
int main()
{
    int t,n,c;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d",&n,&c);
        
        for(int i=0;i<n;i++)
            scanf("%d",&w[i]);
            
        for(int i=c;i>=0;i--)
        {
            if(subsetSum(i,0,n))
            {
                printf("%d\n",c-i);
                break;
            }
        }
    }
    
    return 0;
}
