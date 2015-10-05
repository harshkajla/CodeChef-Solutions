#include <bits/stdc++.h>
using namespace std;
vector<int> f[32];
void reduce(int pos, int bitno) {
    vector<int> temp;
    int flag = 1<<bitno;
    for (int i = 0; i < f[pos].size(); i++) {
        if (f[pos][i]&flag) temp.push_back(f[pos][i]);
    }
    
    if (temp.size() >= 2) f[pos] = temp;
}
int main() {
    int n;
    scanf("%d", &n);
    
    int tmp, x, c;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        tmp = x; c = 0;
        while (tmp) {
            f[c].push_back(x);
            tmp>>=1;
            c++;
        }
    }
    
    int pos = -1;
    for (int i = 31; i >= 0; i--) {
        if (f[i].size() >= 2) {
            pos = i;
            break;
        }
    }
    
    if (pos != -1) {
        for (int i = 31; i >= 0; i--) {
            reduce(pos, i);
        }
        cout << (f[pos][0]&f[pos][1]) << endl;
        return 0;
    }
    
    cout << 0 << endl;
    return 0;
}
