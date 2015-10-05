#include<bits/stdc++.h>
using namespace std;
int findd[200];
char str[1000001];
long long cnt[4][1000001];
long long dp[4][4][1000001];
int main()
{   
    int q,l,r;
    char a,b;
    
    findd['c']=0;
    findd['h']=1;
    findd['e']=2;
    findd['f']=3;
    
    scanf("%s",str);
    
    int len = strlen(str);
    
    //building the DP table.
    for(int i = 0; str[i]; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if(k == j)continue;
                
                //all strings starting at 'j' ending with 'k' till index 'i'.
                if(k == findd[str[i]])
                {
                    dp[j][k][i+1] = dp[j][k][i] + cnt[j][i];
                }
                
                else
                {
                    dp[j][k][i+1] = dp[j][k][i];
                }
            }
            
            if(j == findd[str[i]])
                cnt[j][i+1] = cnt[j][i] + 1;
            else
                cnt[j][i+1] = cnt[j][i];
        }
    }
    
    scanf("%d",&q);
    
    while(q--)
    {
        getchar();
        scanf("%c %c %d %d",&a,&b,&l,&r);
        
        //printf("dp[%c][%c][%d] = %lld\n",a,b,l,dp[findd[a]][findd[b]][l]);
        printf("%lld\n",dp[findd[a]][findd[b]][r] - dp[findd[a]][findd[b]][l-1] - cnt[findd[a]][l-1]*(cnt[findd[b]][r] - cnt[findd[b]][l-1]));
    }
    return 0;
}
