#include<bits/stdc++.h>
using namespace std;
pair<int, int> a[100001];
int main()
{
    int t,n,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            a[i] = make_pair(x,y);
        }
        sort(a, a+n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int j=i+1, prev = a[i].second;
            while(j<n && a[j].first <= prev)
            {
                prev = min(prev, a[j].second);
                j++;
            }
            i=j-1;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
