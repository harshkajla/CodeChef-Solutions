#include<bits/stdc++.h>
using namespace std;
map<string, bool> m;
char str[1001];
int main()
{
    int t,n;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        m.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            m[string(str)]=true;
        }
        scanf("%s",str);
        
        if(m[string(str)])
            puts("yes");
        else
            puts("no");
    }
    
    return 0;
}
