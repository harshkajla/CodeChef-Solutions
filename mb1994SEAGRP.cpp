#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int s=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        sort(a,a+n);
        if(a[0]<2)
        {
            puts("-1");
            continue;
        }
        cout<<s-(a[0]-2)<<endl;
    }
    return 0;
}
