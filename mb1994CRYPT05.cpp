#include<bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    int t;
    lol n,s,del,ans,prev,cur;
    cin >> t;
    
    while(t--)
    {
        cin >> n >> s;
        
        del = n*(n+1)/2-s;
        
        ans=0;
        
        for(int i=n;i>=1 && del !=0;i--)
        {
            prev = i;
            cur = max(1ll,i-del);
            ans++;
            del -= prev - cur;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
