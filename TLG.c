#include<stdio.h>
int main()
{
    int n,diff=0,p1=0,p2=0,person,max=0,t1,t2;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&t1,&t2);
        p1+=t1;p2+=t2;
        if(p1==p2)continue;
        if(p1>p2)
        {
            diff=p1-p2;
            if(diff>max){max=diff;person=1;}
        }
        else if(p1<p2)
        {
            diff=p2-p1;
            if(diff>max){max=diff;person=2;}
        }
    }
    printf("%d %d",person,max);
    return 0;
}
