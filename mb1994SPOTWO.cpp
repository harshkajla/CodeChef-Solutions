#include<bits/stdc++.h>
using namespace std;
char str[100001];
int main()
{
    int t,oct,keys,d,times,ans,temp;
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        scanf("%d",&oct);
        
        keys=12*oct;
        d=0;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='S')
                d+=1;
            else d+=2;
        }
        
        //for each multiple of the scale played:
        times=keys/d;
        ans=0;
        for(int i=1;i<=times;i++)
        {
            temp=keys-i*d;
            if(temp<0)break;
            ans+=temp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
