#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,x,maxlen,start,ans;
    scanf("%d",&n);
    start=0;maxlen=0;ans=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x!=0)
        maxlen++;
        else//x=0
        {
            ans=max(ans,maxlen);
            maxlen=0;
        }
    }
    ans=max(ans,maxlen);
    printf("%d\n",ans);
    return 0;
}
