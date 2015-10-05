#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int a[N], b[N];
pair<int, int> diff[N];
inline bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first >= b.first;
}
int main() {
    int n, x, y, tip;
    scanf("%d %d %d", &n, &x, &y);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        diff[i] = make_pair(abs(a[i]-b[i]), i);
    }
    
    // Sort in descending order of tips.
    sort(diff, diff + n, comp);
    
    int tips = 0;
    int rem[3] = {0, x, y};
    
    for (int i = 0; i < n; i++) {
        int idx = diff[i].second;
        if (a[idx] >= b[idx]) {
            if (rem[1] == 0) {
                rem[2]--;
                tips += b[idx];
            } else {
                rem[1]--;
                tips += a[idx];
            }
        } else {
            if (rem[2] == 0) {
                rem[1]--;
                tips += a[idx];
            } else {
                tips += b[idx];
                rem[2]--;
            }
        }
    }
    
    printf("%d\n", tips);
    return 0;
}
