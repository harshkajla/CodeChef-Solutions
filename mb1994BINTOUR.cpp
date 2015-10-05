#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long mini = *min_element(a, a + n);
        cout << mini*(n-1) << endl;
    }
    return 0;
}
