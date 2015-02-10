#include<bits/stdc++.h>
using namespace std;
string str;
int cnt[1000];
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        char m='\0';
        int maxc=0;
        memset(cnt, 0, sizeof cnt);
        getline(cin,str);
        for(int i=0;str[i];i++)
        {
            if(!isalpha(str[i]))
                continue;
                
            char c=tolower(str[i]);
            cnt[c-'a']++;
            
            if(cnt[c-'a']>maxc)
            {
                m=c;
                maxc=cnt[c-'a'];
            }
            
            else if(cnt[c-'a']==maxc && c>m)
            {
                m=c;
            }
        }
        putchar(tolower(m));
        puts("");
    }
    return 0;
}
