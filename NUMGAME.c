//CODECHEF-NUMGAME
#include<stdio.h>
int main()
{
    int t;long int n;
    
    scanf("%d",&t);
    
    while(t--)
    {
              scanf("%ld",&n);
              if(n&1)
              printf("BOB\n");
              else
              printf("ALICE\n");
              }
return 0;
}
