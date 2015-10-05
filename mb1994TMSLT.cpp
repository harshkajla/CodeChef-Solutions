#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    long long n;
    long long fib[90], s[90];
    
    //precomputing fibonacci series.
    fib[0] = 1; s[0] = 1;
    fib[1] = 1; s[1] = 2;
    for (int i = 2; i <= 89; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        s[i] = s[i-1] + fib[i];
    }
    
    scanf("%d", &t);
    
    while (t--) {
        scanf("%lld", &n);
        for (int i = 0; i <= 89; i++) {
            if (s[i] >= n) {
                printf("%d\n", i + 1);
                break;
            }
        }    
    }
    
    return 0;
}
