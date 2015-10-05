#include<bits/stdc++.h>
using namespace std;
int a[123456];
int main()
{
    int t,n,ans;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && a[i]!=a[i-1])
            {
                ans++;
                continue;
            }
            
            if(i<n-1 && a[i]!=a[i+1])
                ans++;
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
