#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
vector<pair<int, int> > factors[N];
map<int, int> m;
bool marked[N];
void factorize() {
    int tmp, p;
    for (int i = 2; i <= N; i++) {
        if (!marked[i])
        for (int j = i<<1; j <= N; j += i) {
            marked[j] = true;
            tmp = j; p = 0;
            while (tmp%i == 0) {
                tmp/=i;
                p++;
            }
            factors[j].push_back(make_pair(i, p));
        }
    }
    
    for (int i = 2; i <= N; i++) 
        if (!marked[i])
            factors[i].push_back(make_pair(i, 1));
}
int main() {
    int t, n, fact, p, x;
    
    factorize();
    scanf("%d", &t);
    
    while (t--) {
        m.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            for (int j = 0; j < factors[x].size(); j++) {
                fact = factors[x][j].first;
                p = factors[x][j].second;
                
                m[fact] += p;
            }
        }
        
        long long ans = 1;
        for (map<int, int>::iterator i = m.begin(); i != m.end(); i++) {
            ans *= (i->second+1);
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}
