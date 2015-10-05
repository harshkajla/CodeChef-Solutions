#include<stdio.h>
#include<string.h>
int cnt[130];
char str[1001];
int main()
{
    int t,maxc;
    char maxchar;
    
    scanf("%d",&t);
    
    while(t--)
    {
        maxc=0;
        memset(cnt,0,sizeof cnt);
        
        scanf("%s",str);
        
        maxchar='z'+1;
        for(int i=0;str[i];i++)
        {
            cnt[str[i]-'a']++;
            if(cnt[str[i]-'a']==maxc)
            {
                if(maxchar>str[i])
                maxchar=str[i];
            }
            
            else if(cnt[str[i]-'a']>maxc)
            {
                maxchar=str[i];
                maxc=cnt[str[i]-'a'];
            }
        }
        
        for(int i=0;str[i];i++)
        {
            if(str[i]==maxchar)
            str[i]='?';
        }
        
        printf("%s\n",str);
    }
    
    return 0;
}
