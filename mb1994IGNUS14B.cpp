#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
	int t, n;
	long long k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %lld", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		long long bags = 1, curbag = k;
		for (int i = 0; i < n; i++) {
			if (curbag == a[i]) {
				curbag = 0;
			} else if (curbag > a[i]) {
				curbag -= a[i]+1;
			} else {
				a[i] -= curbag;
				bags += (a[i]/k) + (a[i]%k!=0);
				if (a[i]%k) {
					curbag = k-(a[i]%k);
					if (curbag) curbag--;	
				} else curbag = 0;
			}
		}
		printf("%lld\n", bags);
	}
	return 0;
}
