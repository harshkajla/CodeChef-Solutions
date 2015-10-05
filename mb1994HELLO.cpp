#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
long long f[32];
int main() {
    int n;
    scanf("%d", &n);
    
    int c, x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        c = 0;
        while (x) {
            f[c] += (x&1);
            x>>=1;
            c++;
        }
    }
    
    long long ans = 0, tmp;
    for (int i = 0; i < 32; i++) {
        tmp = f[i]*(f[i]-1)/2;
        tmp <<= i;
        
        ans += tmp;
    }
    
    cout << ans << endl;
    return 0;
}
