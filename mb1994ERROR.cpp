#include<bits/stdc++.h>
using namespace std;
map<int, string> first;
map<string, int> m;
string str;
int main()
{
    int n,x;
    cin>>n;
    
    int maxi=INT_MIN;
    string ans="";
    
    while(n--)
    {
        cin>>str>>x;
        m[str]+=x;
        
        if(first.find(m[str])==first.end())
            first[m[str]]=str;
        if(m[str]>maxi)
        {
            maxi=m[str];
            ans=str;
        }
    }
    cout<<ans<<endl;
    return 0;
}
