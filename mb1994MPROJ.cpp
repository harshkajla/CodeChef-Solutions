#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	string front, back, left, right, top, bottom;
	scanf("%d", &t);
	while (t--) {
		bool ok = false;
		cin >> front >> back >> left >> right >> top >> bottom;
		if (right == front and front == top and top == right) ok = true;
		else if (top == left and left == front and front == top) ok = true;
		else if (top == back and back == left and left == top) ok = true;
		else if (top == right and right == back and back == top) ok = true;
		if (right == front and front == bottom and bottom == right) ok = true;
		else if (bottom == left and left == front and front == bottom) ok = true;
		else if (bottom == back and back == left and left == bottom) ok = true;
		else if (bottom == right and right == back and back == bottom) ok = true;
		puts (ok? "YES":"NO");
	}
	return 0;
}
