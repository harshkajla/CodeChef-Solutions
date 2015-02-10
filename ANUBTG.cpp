#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
    int t, n;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]);
            
        sort(a,a+n);
        
        int ans = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            ans += a[i];
            
            if(i >= 1)
            {
                ans += a[i - 1];
                i-=3;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
