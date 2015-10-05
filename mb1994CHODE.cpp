#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    long long x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(y%x!=0)
            puts("WRONG");
        else puts("CORRECT");
    }
    return 0;
}
