#include<stdio.h>
int main()
{
    int t,menu,i,p,j;
    int a[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
    scanf("%d",&t);
    while(t--)
    {menu=0;
        scanf("%d",&p);
            for(i=11;i>=0;i--)
            {j=i;
                if(p%a[i]==0){menu+=p/a[i];break;}
                if(a[i]<=p){p-=a[i];menu++;i=j+1;}
            }
    printf("%d\n",menu);
    }
    return 0;
}
