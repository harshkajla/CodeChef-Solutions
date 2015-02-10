#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double a,b,c;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%lf %lf %lf",&a,&b,&c);
        
        double num = a*b*c;
        double denom=(a+b+c)*(b+c-a)*(c+a-b)*(a+b-c);
        
        printf("%.2lf\n",num/sqrt(denom));
    }
    return 0;
}
