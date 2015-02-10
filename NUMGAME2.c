#include <stdio.h>
 
int main(void)
{
    int T;
    long val;
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%ld",&val);
        --val%4 ? printf("BOB\n") : printf("ALICE\n");
    }
    return 0;
}
