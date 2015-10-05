#include<bits/stdc++.h>
using namespace std;
int cnt[26];
char ans[1000010];
char str[1000001];
vector<int> pos;
int main() {
    int t,n,times;
    char x;
    scanf("%d",&t);
    
    while(t--) {
        scanf("%s",str);
        
        memset(cnt, 0, sizeof cnt);
        int n=0;
        for(int i=0;str[i];i++) {
            cnt[str[i]-'a']++;
            n++;
        }
        
        vector<pair<int, char> >vec;
        for(int i=0;i<26;i++) {
            if(cnt[i]) {
                vec.push_back(make_pair(cnt[i],i+'a'));
            }
        }
        
        sort(vec.begin(),vec.end());
        
        pos.clear();
        for(int i=0;i<n;i+=2)
        pos.push_back(i);
        
        for(int i=1;i<n;i+=2)
        pos.push_back(i);
        
        int c = 0;
        for(int i=vec.size()-1;i>=0;i--) {
            x = vec[i].second;
            times = vec[i].first;
            for(int j = 1; j <= times; j++) {
                ans[pos[c++]] = x;
            }
        }
        ans[n] = '\0';
        bool ok = true;
        for(int i=1;i<n;i++) {
            if(ans[i] == ans[i-1]) {
                ok = false;
                break;
            }
        }
        
        if(!ok) {
            puts("-1");
        }
        
        else printf("%s\n",ans);
    }
    return 0;
}
