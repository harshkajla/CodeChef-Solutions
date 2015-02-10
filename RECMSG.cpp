#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        cin>>str;
        
        int ans = 0;
        for(int i=0;i<str.size();i++)
            ans += str[i]-'a' + 1;
        cout<<ans<<endl;
    }
    return 0;
}
