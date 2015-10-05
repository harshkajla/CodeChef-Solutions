#include<iostream>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;
const int N = 5001;
const long long mod = 1000000007;
map<string, int> mm;
int cnts[N];
string str;
long long ncr[N][N];
void precompute() {
	//precomputes NCR values..
	for(int i=1;i<N;i++) {
		for(int j=0;j<=i;j++) {
			if(j==0||i==j) {
				ncr[i][j] = 1;
			}
			else ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
			if(ncr[i][j] >= mod) ncr[i][j] %= mod;
		}
	}
}
int main() {
	int t,n,q,k;
	precompute();
	scanf("%d",&t);
	while(t--) {
		mm.clear();
		scanf("%d%d",&n,&q);
		cin>>str;
		for(int i=0;i<=n;i++) cnts[i] = 0;
		//storing count of the substrings..
		for(int i=0;i<str.size();i++) {
			for(int j=i;j<str.size();j++) {
				mm[str.substr(i,j-i+1)]++;
			}
		}
		for(map<string, int>::iterator i = mm.begin(); i!=mm.end(); i++) {
			//find no of (i->second) identical strings.
			//cnt[i] stores number of identical substrings whose occurence is i.
			cnts[i->second]++;
		}
		long long ans = 0, temp;
		while(q--) {
			scanf("%d",&k);
			ans = 0;
			for(int i=k;i<=N;i++) {
				temp = ncr[i][k];
				temp *= cnts[i];
				if(temp >= mod) temp %= mod;
				ans += temp;
				if(ans >= mod) ans %= mod;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
