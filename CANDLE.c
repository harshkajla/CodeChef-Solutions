#include<stdio.h>
#include<math.h>
int main()
{
    int t,min,i,min1,min2,candles[10];
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<10;i++)
            {
                scanf("%d",&candles[i]);
            }
            min1=(long int)pow(10,candles[0]+1);
            //finding minimum repdigit
            min2=1;
            for(i=2;i<10;i++)
                if(candles[i]<candles[min2])
                min2=i;
            min=min2;
            candles[min2]--;
            while(candles[min2]!=-1)
            {
                min=min*10+min2;
                candles[min2]--;
            }
            if(min<min1)
            {
                printf("%ld\n",min);
            }
            else
            {
                printf("%ld\n",min1);
            }
    }
    return 0;
}
