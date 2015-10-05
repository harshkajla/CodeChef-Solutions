#include<bits/stdc++.h>
using namespace std;
map<long long, vector<int> > m;
int a[500001];
long long s[500001];
int main()
{
    int n;
    scanf("%d",&n);
    m.clear();
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0)s[i] = a[i];
        else s[i]=s[i-1]+a[i];
        
        m[s[i]].push_back(i);
    }
    
    if(s[n-1]%3 !=0)
    {
        puts("0");
        return 0;
    }
    
    int x = s[n-1]/3;
    int y = x<<1;
    vector<int> a = m[x];
    vector<int> b = m[y];
    
    long long ans=0;
    int cnt=0;
    for(int i=b.size()-1;i>=0;i--)
        if(b[i]==n-1)cnt++;
        
    for(int i = 0; i < a.size(); i++)
    {
        int pos = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(pos == b.size())
        continue;
        if(pos != b.size() && b[pos]!=n-1)
            ans+=b.size()-pos-cnt;
    }
    
    printf("%lld\n",ans);
    return 0;
}
