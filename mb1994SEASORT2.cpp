#include <bits/stdc++.h>
using namespace std;
int x[250001], y[250001];
int manhattan(int i, int j) {
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}
int main() {
	int t, n, tmp;
	
	cin >> t;
	while (t--) {
	    cin >> n;
	    
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            cin >> tmp;
	            x[tmp] = i;
	            y[tmp] = j;
	        }
	    }
	    
	    int nn = n * n;
	    int dist = 0;
	    for (int i = 2; i <= nn; i++) {
	        dist += manhattan(i-1, i);
	    }
	    cout << dist << endl;
	}
	
	return 0;
}
