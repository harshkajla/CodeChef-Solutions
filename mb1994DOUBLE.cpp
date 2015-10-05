#include<bits/stdc++.h>
using namespace std;
vector<int> vec[100007];
vector<pair<int, int> > bars;
map<int, int> m;
int main() {
    int n,x,y,c;
    scanf("%d",&n);
    
    while(n) {
        
        c = 0;
        m.clear();
        
        for(int i = 0; i < n; i++) {
            scanf("%d%d",&x,&y);
            
            if(m[x]) {
                vec[m[x]].push_back(y);
            }
            
            else {
                m[x] = ++c;
                vec[c].clear();
                vec[c].push_back(y);
            }
        }
        
        bars.clear();
        for(int i = 1; i <= c; i++) {
            if(vec[i].size() == 2) {
                //printf("bar = (%d,%d),(%d,%d)\n",i,vec[i][0],i,vec[i][1]);
                bars.push_back(make_pair(min(vec[i][0],vec[i][1]),abs(vec[i][0]-vec[i][1])));
            }
        }
        
        long long ans = 0;
        sort(bars.begin(),bars.end());
        
        for(int i = 0; i < bars.size(); i++) {
            int j = i + 1;
            long long temp = 1;
            while(j < bars.size() && bars[j] == bars[j-1]) {
                j++;
                temp++;
            }
            i = j - 1;
            ans += (temp)*(temp-1)/2;
        }
        printf("%lld\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
