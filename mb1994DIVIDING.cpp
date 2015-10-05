#include <bits/stdc++.h>
using namespace std;
int a[100001];
multiset<int> s;
map<int, int> m;
int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        s.clear();
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
        }
        
        m.clear();
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                s.insert(a[i]);
                m[a[i]]++;
                len++;
                continue;
            } else {
                set<int>::iterator ii = s.upper_bound(a[i]);
                if (ii == s.end()) {
                    s.insert(a[i]);
                    m[a[i]]++;
                    len++;
                } else {
                    s.erase(ii);
                    m[*ii]--;
                    s.insert(a[i]);
                    m[a[i]]++;
                }
            }
        }
        
        cout << len << " ";
        for (set<int>::iterator ii = s.begin(); ii != s.end(); ii++) {
            while (m[*ii]) {
                cout << *ii << " ";
                m[*ii]--;
            }
        }
        cout << endl;
    }
    return 0;
}
