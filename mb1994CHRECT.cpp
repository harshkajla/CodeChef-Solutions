/**
 * January 2013 Long Challenge at Codechef
 *
 * Problem:     THREEDIF - Three Different Numbers
 * Author:      Anton Lunyov (Problem-Setter and Editorialist)
 * Complexity:  O(1) per test
 * Timing:      0.000 out of 2.013 (Happy New Year to all!)
 *
 * Description:
 * The simplest solution uses the formula N1*(N2-1)*(N3-2), where N1<=N2<=N3
 * But in this solution we apply inclusion-exclusion principle.
 * We at first count the number of all possible triples, which is N1 * N2 * N3.
 * Then we exclude triples where X1=X2. There are min(N1,N2) * N3 such triples.
 * Similarly we exclude triples with X2=X3 and then with X1=X3.
 * But each triple with X1=X2=X3 have now count -2 in our number:
 * it was included one time when we consider all triples and was excluded three times
 * when we consider triples having some two elements equal.
 * Hence we need to add twice of number of such triples which is min(N1,N2,N3).
 * Therefore, we get the formula for the number of required triples:
 * N1*N2*N3 - min(N1,N2)*N3 - min(N1,N3)*N2 - min(N2,N3)*N1 + 2*min(N1,N2,N3)
 * Interestingly but if we assume here N1<=N2<=N3, calculate each minimum
 * and do some obvious calculation we get the above simple formula.
 */
#include <iostream>
using namespace std;
typedef long long LL;
// the modulo 10^9 + 7
const int MOD = 1000000007;
// return the product a * b modulo MOD
LL MUL(LL a, LL b) {
	a %= MOD;
	b %= MOD;
	return a * b % MOD;
}
int main() {
	// input number of tests
	int T;
	cin >> T;
	// loop over tests
	for (int t = 0; t < T; ++t) {
		// input numbers N1, N2, N3
		LL N1, N2, N3;
		cin >> N1 >> N2 >> N3;
		// we can't take numbers N1, N2, N3 modulo MOD initially
		// since min(A, B) mod MOD != min(A mod MOD, B mod MOD) in general
		// answer is N1*N2*N3 - min(N1,N2)*N3 - min(N1,N3)*N2 - min(N2,N3)*N1 + 2*min(N1,N2,N3)
		LL ans = MUL(MUL(N1, N2), N3);
		ans -= MUL(min(N1, N2), N3);
		ans -= MUL(min(N1, N3), N2);
		ans -= MUL(min(N2, N3), N1);
		ans += 2 * min(min(N1, N2), N3);
		ans %= MOD;
		// 'ans' could be negative now
		// it is very important to do this check
		if(ans < 0) {
			ans += MOD;
		}
		// output the answer
		cout << ans << endl;
	}
}
