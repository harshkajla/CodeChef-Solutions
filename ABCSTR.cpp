#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, int > m;
int cnt[3];
char str[1000001];
int main()
{
    long long ans=0;
    pair<int, int> tmp;
    scanf("%s",str);
    m[make_pair(0,0)]++;
    for(int i=0;str[i];i++)
    {
        cnt[str[i]-'A']++;
        tmp=make_pair(cnt[0]-cnt[1],cnt[0]-cnt[2]);
        ans+=m[tmp];
        m[tmp]++;
    }
    cout<<ans<<endl;
}
