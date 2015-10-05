#include<bits/stdc++.h>
using namespace std;
int main() {
	int t,n,k,x;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d", &n, &k);
		int s = 0;
		for(int i=0;i<n;i++) {
			scanf("%d",&x);
			s+=x;
			if(s>=2)s=s&1;
		}
		if(k>=2) puts("even");
		else {
			if(s == 0) {
				puts("odd");
			} else puts("even");
		}
	}
	return 0;
}
