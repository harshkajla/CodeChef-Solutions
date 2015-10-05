#include <bits/stdc++.h>
using namespace std;
vector<long long> twos;
int main() {
    int t;
    long long l, r;
    
    scanf("%d", &t);
    
    while (t--) {
        scanf("%lld %lld", &l, &r);
        
        //numbers of form 2^i, i>=0.
        long long tmp = 1;
        int ans = 0;
        twos.clear();
        
        while (tmp <= r) {
            if (tmp >= l) ans++;
            if (tmp != 1) twos.push_back(tmp);
            tmp<<=1;
        }
        
        //number of form 2^i x 3^j, i and j >= 1.
        for (int i = 0; i < twos.size(); i++) {
            tmp = twos[i]*3;
            while (tmp <= r) {
                if (tmp >= l) ans++;
                tmp = (tmp<<1) + tmp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
