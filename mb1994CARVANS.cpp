#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    long long k,x;
    scanf("%d",&t);
    
    while(t--) {
        scanf("%d %lld",&n, &k);
        long long ans = 0;
        while(n--) {
            scanf("%lld",&x);
            long long n1 = x / k;
            long long n2;
            n1*=k;n2=n1+k;
            
            if(n1 == 0) {
                ans += abs(n2-x);
            }
            else {
                ans += min(abs(n1-x),abs(n2-x));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
