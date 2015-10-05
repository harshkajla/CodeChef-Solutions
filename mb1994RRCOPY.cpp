#include <bits/stdc++.h>
using namespace std;
int a[20001];
int cuts(int i, int j) {
    if (i >= j) return 0;
    if (i == j - 1) return 1;
    else if (i == j - 2) {
        if (a[i] == 1) return 1;
        else return 2;
    }
    
    if (a[i] == 1) return 1 + cuts(i + 1, j - 1);
    else return 2 + cuts(i + 1, j - 1);
}
int main() {
    int t, n, m;
    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        
        for (int i = 0; i < m; i++) cin >> a[i];
        sort(a, a + m);
        cout << cuts(0, m - 1) << endl;
    }
    
    return 0;
}
