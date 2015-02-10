#include<stdio.h>
#include<string.h>
char votes[101][21];
int search(char* name, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(name,votes[i])==0)
        return i;
    }
    return -1;
}
int main()
{
    int t,x,total,i,n,len,j;
    char temp[21],c;
    int vote[101];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<101;i++)
        vote[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",votes[i]);
            getchar();
            c=getchar();
            if((x=search(votes[i],i))!=-1)
            {
                vote[x]=(c=='+')?1:-1;
            }
            else
            vote[i]=(c=='+')?1:-1;
        }
        total=0;
        for(i=0;i<n;i++)
        {
            total+=vote[i];
        }
        printf("%d\n",total);
    }
    return 0;
}
