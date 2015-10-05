#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &a, &b);
        int val = 0;
        while (a != b) {
            if (a > b) swap(a,b);
            
            val++;
            b >>= 1;
        }
        printf("%d\n", val);
    }
    return 0;
}
