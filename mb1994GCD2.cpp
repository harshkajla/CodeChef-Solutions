#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
long long sum[N + 1];
int main() {
	int t, n, h, l, r;
	cin >> t;
	while (t--) {
		cin >> n >> h;
		
		for (int i = 0; i <= n; i++) sum[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> l >> r;
			sum[l]++;
			sum[r+1]--;
		}
		
		long long cur = 0;
		for (int i = 0; i < n; i++) {
			cur += sum[i];
			sum[i] = n - cur;
		}
		
		long long minCost = 0;
		for (int i = 0; i < h; i++) {
			minCost += sum[i];
		}
		
		cur = minCost;
		for (int i = h; i < n; i++) {
			cur = cur - sum[i - h] + sum[i];
			if (cur < minCost) minCost = cur;
		}
		
		printf("%lld\n", minCost);
	}
	return 0;
}
