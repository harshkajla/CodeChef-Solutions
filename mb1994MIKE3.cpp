#include <bits/stdc++.h>
using namespace std;
map<string, bool> m, done;
string a[100];
int main() {
    string str;
    int t, n, k;
    scanf("%d", &t);
    
    while (t--) {
        m.clear();
        done.clear();
        
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) {
            cin >> str;
            a[i] = str;
            m[str] = true;
        }
    
        int x;
        for (int i = 0; i < k; i++) {
            scanf("%d", &x);
            for (int j = 0; j < x; j++) {
                cin >> str;
                done[str] = true;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (done[a[i]]) cout << "YES ";
            else cout << "NO ";
        }
        cout << endl;
    }
    return 0;
}
