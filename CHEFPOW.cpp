#include<cstdio>
int n,c=1;main(){scanf("%d",&n);while(n){if(n&1)printf("%d ",c);c*=2;n/=2;}}
