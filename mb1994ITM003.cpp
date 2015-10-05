#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);    int a[n];
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+m);
        for(int i=0;i<n;i++)
        {
            printf("%d ",max(abs(i-a[0]),abs(i-a[m-1])));
        }
        puts("");
    }
}
