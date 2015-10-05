#include<bits/stdc++.h>
using namespace std;
int dp[2100][30][30];
int main()
{
    int t;string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        
        memset(dp, 0, sizeof dp);
        
        str="#"+str;
        
        for(int i=1;i<str.size();i++)
        {
            for(int j='a';j<='z';j++)
            {
                for(int k='a';k<='z';k++)
                {
                    dp[i][j-'a'][k-'a']=max(dp[i][j-'a'][k-'a'],dp[i-1][j-'a'][k-'a']);
                    
                    if(j<=str[i])
                    {
                        dp[i][str[i]-'a'][k-'a']=max(dp[i][str[i]-'a'][k-'a'], dp[i-1][j-'a'][k-'a']+1);
                    }
                    if(k>=str[i])
                    {
                        dp[i][j-'a'][str[i]-'a']=max(dp[i][j-'a'][str[i]-'a'], dp[i-1][j-'a'][k-'a']+1);
                    }
                }
            }
        }
        
        //go thru all dp states to find the max..
        int ans=0;
        for(int j=0;j<26;j++)
        {
            for(int k=0;k<26;k++)
            {
                ans=max(ans,dp[str.size()-1][j][k]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
