#include<bits/stdc++.h>
using namespace std;
double prob[51][51][101];
int main()
{
    int t,n,c,k,l,r,K;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d %d %d",&n,&c,&K);
        memset(prob, 0, sizeof prob);
        
        //prob of color 1 is 1 for 0th turn
        for(int i = 0; i < n; i++)
        {
            prob[0][i][1] = 1.0;
        }
        
        //now for each turn..
        for(int i=1;i<=K;i++)
        {
            scanf("%d %d",&l,&r);
            l--;r--;
            
            //for all indices not in range [l,r]:
            for(int j=0;j<n;j++)
            {
                if(j<l || j>r)
                for(int k=0;k<c;k++)
                {
                    prob[i][j][k] = prob[i-1][j][k];
                }
            }
            
            //for indices in range [l,r]:
            for(int j=l;j<=r;j++)
            {
                //for each index in [l,r]:
                for(int k=0;k<c;k++)
                {
                    prob[i][j][k] += prob[i-1][j][k]/2.0;
                    for(int kk=0;kk<c;kk++)
                    {
                        //was initially kth color..now its being painted by kkth color..
                        prob[i][j][(k*kk)%c] += prob[i-1][j][k]/(2.0*c);
                    }
                }
            }
        }
            
        double ans=0.0;
        for(int i=0;i<n;i++)
            for(int j=0;j<c;j++)
                ans += j*prob[K][i][j];
                    
        printf("%.9lf\n",ans);
    }
    
    return 0;
    
}
