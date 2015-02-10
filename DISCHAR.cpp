#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool marked[150];
char str[100001];
int main()
{
    int t;
    
        scanf("%d",&t);
        
        while(t--)
        {
            memset(marked, false, sizeof marked);
            
            scanf("%s",str);
            int ans=0;
            for(int i=0;str[i];i++)
            {
                if(!marked[str[i]-'a'])
                {
                    marked[str[i]-'a']=true;
                    ans++;
                }
            }
            
            printf("%d\n",ans);
        }
        
        return 0;
}
