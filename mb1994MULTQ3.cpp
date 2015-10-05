#include<stdio.h>
#include<math.h>
typedef long long int ll;
inline ll gcd(ll a, ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    int t;
    ll n,m,o1,o2,e1,e2,numerator,denominator,gc;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        o1=ceil(n/2.0);
        o2=ceil(m/2.0);
        e1=n-o1;
        e2=m-o2;
        numerator=e1*o2+o1*e2;
        denominator=n*m;
        gc=gcd(numerator,denominator);
        printf("%lld/%lld\n",numerator/gc,denominator/gc);
    }
    return 0;
}
