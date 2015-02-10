#include<stdio.h>
int main()
{
    int t;
    long int n,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld%ld",&n,&c);
        if(n<=c){printf("0\n");continue;}
        n-=c;
        printf("%ld\n",n/c+(n%c!=0));
    }
    return 0;
}
