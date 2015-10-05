#include <bits/stdc++.h>
using namespace std;
int cost(int i, string s[]) {
    if (s[i][0] == '#') return INT_MAX;
    
    int cost = 0, j = 1;
    while (j < s[i].size()) {
        if (s[i][j] == '#') {
            if (s[1 - i][j] == '#') return INT_MAX;
            else {
                cost++;
                i = 1 - i;
            }
        } else {
            j++;
        }
    }
    return cost;
}
int main() {
    int t;
    string s[2];
    
    scanf("%d", &t);
    
    while (t--) {
        cin >> s[0] >> s[1];
        int l = s[0].size();
        
        int v1 = cost(0, s);
        int v2 = cost(1, s);
        
        v2 = min(v1, v2);
        if (v2 == INT_MAX) {
            puts("No");
        } else {
            puts("Yes");
            cout << v2 << endl;
        }
    }
    return 0;
}
