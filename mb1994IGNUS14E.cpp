#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long num;
		cin >> num;
		int p5 = 0;
		long long temp = num;
		while (num % 5 == 0) {
			num /= 5;
			p5++;
		}
		num = temp;
		int p2 = 0;
		while (num % 2 == 0) {
			num >>= 1;
			p2++;
		}
		int times = (p5 - p2 + 1) / 2;
		for (int i = 1; i <= times; i++) {
			temp <<= 2;
		}
		printf("%lld\n", temp);
	}
	return 0;
}
