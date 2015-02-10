#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[100][100];
int main()
{
    int t,i,j,maxi,n;
    scanf("%d",&t);
    while(t--)
    {
        //input no of lines
        scanf("%d",&n);
        for(i=0;i<n;i++)
        for(j=0;j<=i;j++)
        {
            scanf("%d",&dp[i][j]);
        }
        //finding the best path
        for(i=1;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                //if first column:
                if(j==0)
                dp[i][j]+=dp[i-1][j];
                else
                dp[i][j]+=max(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        //traverse the last row to find max sum
        maxi=0;
        for(i=0;i<n;i++)
        if(dp[n-1][i]>maxi)maxi=dp[n-1][i];
        printf("%d\n",maxi);
    }
    return 0;
}
