#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    long long int x,y,ans,dx,dy;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&x,&y);
        if(x<0)x=-x;
        if(y<0)y=-y;
        if(x>y)
        {
            ans=y*2;
            x-=y;
            dx=(x+1)/2;
            ans+=dx*3+(x-dx);
            printf("%lld\n",ans);
        }
        else if(y>x)
        {
            ans=x*2;
            y-=x;
            dy=(y+1)/2;
            ans+=dy+(y-dy)*3;
            printf("%lld\n",ans);
        }
        else
        {
            printf("%lld\n",2*x);
        }
    }
    return 0;
}
