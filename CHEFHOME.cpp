#include<bits/stdc++.h>
using namespace std;
long long x[1001];
long long y[1001];
int main()
{
    int t,n;
    long long sumx,sumy,ans;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        sumx=0;sumy=0;
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
            sumx+=x[i];
            sumy+=y[i];
        }
        
        sort(x,x+n);
        sort(y,y+n);
        
        if(n&1)
        ans=1;
        
        else
        {
            long long ansx = x[n/2]-x[n/2-1]+1;
            long long ansy = y[n/2]-y[n/2-1]+1;
            
            ans=ansx*ansy;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
