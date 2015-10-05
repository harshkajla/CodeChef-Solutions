#include<stdio.h>
int main()
{
    int n,i,j,ans;
    scanf("%d",&n);
    int a[n];
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    ans=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((a[i]&a[j])>ans)
            {
                ans=a[i]&a[j];
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
