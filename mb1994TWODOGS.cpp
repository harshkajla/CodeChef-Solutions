#include<bits/stdc++.h>
#define lol long long
using namespace std;
const int N = 2010;
const int M = 2010;
const long long mod = 1000000000;
long long ways[N][M], ncr[N+M][N+M],  sum[N][M];
int main() {
	int t,n,m;
	for(int i=0;i<=2*M;i++) {
		for(int j=0;j<=i;j++) {
			if(i==0){ncr[i][j]=1;continue;}
			if(j==0||j==i) ncr[i][j]=1;
			else ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
			if(ncr[i][j]>=mod)ncr[i][j]%=mod;
		}
	}
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i=0;i<=m;i++) {
			ways[1][i] = ncr[i+m-1][m-1];
			sum[1][i] = ways[1][i];
			if(i>0)sum[1][i] += sum[1][i-1];
			if(sum[1][i]>=mod)sum[1][i]%=mod;
		}
		for(int i=2;i<=n;i++) {
			for(int j=0;j<=m;j++) {
				ways[i][j] = sum[i-1][j]*ways[1][j];
				if(ways[i][j]>=mod)ways[i][j]%=mod;
				sum[i][j] = ways[i][j];
				if(j>0)sum[i][j] += sum[i][j-1];
				if(sum[i][j]>=mod)sum[i][j]%=mod;
			}
		}
		printf("%lld\n",sum[n][m]);
	}
	return 0;
}
