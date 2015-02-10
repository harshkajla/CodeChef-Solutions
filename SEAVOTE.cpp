#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int cnt=0,sum=0;
        bool possible = true;
        for(int i=n-1;i>=0;i--)
        {
            cnt++;
            sum+=a[i];
            if(a[i]>100 || sum>100+cnt-1)
            {
                possible = false;
                break;
            }
        }
        if(sum<100)
            possible = false;
        puts(possible? "YES" : "NO");
    }
    return 0;
}
