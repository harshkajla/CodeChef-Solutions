#include<bits/stdc++.h>
using namespace std;
bool marked[101];
int main() {
    int t,n,x;
    cin>>t;
    
    while(t--) {
        cin>>n;
        
        memset(marked, false,sizeof marked);
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            cin>>x;
            if(!marked[x]) {
                marked[x] = true;
                ans++;
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
