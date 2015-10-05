#include<bits/stdc++.h>
using namespace std;
const int N = 1234567;
long long cost[N];
int start[N], deg[N], to[N];
int main() {
    int t,n;
    
    scanf("%d",&t);
    
    while(t--) {
        scanf("%d",&n);
        
        for(int i=1;i<=n;i++) {
            scanf("%d",to+i);
            deg[i] = 0;
        }
        
        for(int i = 1; i <= n; i++) {
            scanf("%lld",cost+i);
            deg[to[i]]++;
        }
        
        //start with all source nodes.
        int x = 0;
        for(int i=1;i<=n;i++) {
            if(deg[i] == 0) {
                start[x++] = i;
            }
        }
        
        for(int i=0;i<x;i++) {
            int v = start[i];
            
            cost[to[v]]+=max(0ll, cost[v]);
            deg[to[v]]--;
            if(deg[to[v]] == 0) {
                start[x++] = to[v];
            }
        }
        
        //now i only have cycles left.
        long long ans = 0;
        for(int i=1;i<=n;i++) {
            
            if(deg[i] == 0) continue;
            
            int p = i;
            long long temp = 0;
            while(deg[p] > 0) {
                temp += cost[p];
                deg[p]--;
                p = to[p];
            }
            
            ans += max(temp,0ll);
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
