#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
using namespace std;
long long a[100001];
int main() {
	int t,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
			scanf("%lld",a+i);
		}
		long long ans = a[0];
		for(int i=1;i<n;i++) {
				if(a[i]>a[i-1]) {
					ans+=a[i]-a[i-1];
				}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
