#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    long long x,mini,maxi;
    
    cin>>t;
    while(t--)
    {
        cin>>n;
        mini=LONG_LONG_MAX;
        maxi=LONG_LONG_MIN;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            mini=min(x,mini);
            maxi=max(x,maxi);
        }
        long long diff=maxi-mini;
        if(diff>=2)
        {
            puts("BAD");
        }
        else puts("GOOD");
    }
    return 0;
}
