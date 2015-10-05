#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> >polygons;
int ans[100001];
int main() {
	int t,n,sides,xmax,x,y;
	scanf("%d",&t);
	while(t--) {
		polygons.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++) {
			scanf("%d",&sides);
			xmax = INT_MIN;
			for(int j=0;j<sides;j++) {
				scanf("%d%d",&x,&y);
				xmax = max(xmax, x);
			}
			polygons.push_back(make_pair(xmax,i));
		}
		sort(polygons.begin(),polygons.end());
		for(int i=0;i<n;i++) {
			ans[polygons[i].second] = i;
		}
		for(int i=0;i<n;i++) {
			printf("%d ",ans[i]);
		}puts("");
	}
	return 0;
}
