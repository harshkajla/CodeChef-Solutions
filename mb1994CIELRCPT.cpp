#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(gcd(n,i)==1)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
