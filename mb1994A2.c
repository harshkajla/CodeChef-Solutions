#include<stdio.h>
int main()
{
    int called[46]={0},f,i,j,count,arr[6],bonus,n;
    for(i=0;i<6;i++)
    {
        scanf("%d",&n);;
        called[n]=1;
    }
    scanf("%d",&bonus);
    for(i=0;i<5;i++)
    {
        count=0;
        for(j=0;j<6;j++)
        {
            scanf("%d",&arr[j]);
            if(called[arr[j]]==1)
                count++;
        }
        //printf("count=%d\n",count);
        switch(count)
        {
        case 6:
            printf("First Parking slot\n");
            break;
        case 5:
            f=0;
            for(j=0;j<6;j++)
            {
                if(called[arr[j]]==0)
                    if(arr[j]==bonus)
                    {printf("Second Parking slot\n");f=1;break;}
            }
            if(f==0)
                printf("Third Parking slot\n");
            break;
        case 4:
            printf("Fourth Parking slot\n");
            break;
        case 3:
            printf("Fifth Parking slot\n");
            break;
        default:
            printf("No Parking slot\n");
        }
    }
return 0;
}
