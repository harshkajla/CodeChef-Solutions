#include<stdio.h>
int main()
{
    int t,j,g,i,q,finalFirstCoin;
    long int n,numofSuchCoins,numofHeads,reqValue;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&g);
        for(j=0;j<g;j++)
        {
            scanf("%d%ld%d",&i,&n,&q);
            //0 is head, 1 is tail. Taking all head initiall
            finalFirstCoin=n%2;
            numofSuchCoins=ceil(n/2.0);
            numofHeads=(finalFirstCoin==0)?numofSuchCoins:(n-numofSuchCoins);
            if(i==q)
                reqValue=numofHeads;
            else
                reqValue=n-numofHeads;
            printf("%ld\n",reqValue);
        }
    }
    return 0;
}
