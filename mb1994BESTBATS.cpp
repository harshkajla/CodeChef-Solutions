#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&s);
        
        int ans=0;
        while(s)
        {
            ans++;
            s=s&(s-1);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
