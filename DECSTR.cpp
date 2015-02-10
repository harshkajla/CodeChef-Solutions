#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
int main()
{
    int t,k,l,i;
    string x="abcdefghijklmnopqrstuvwxyz";
    string ans;
    scanf("%d",&t);
    while(t--)
    {
        ans="";
        scanf("%d",&k);
        while(k>=25)
        {
            ans=ans+x.substr(0,26);
            k-=25;
        }
        if(k!=0)
        ans+=x.substr(0,k+1);
        l=ans.size();
        for(i=l-1;i>=0;i--)
        {
            putchar(ans.at(i));
        }
        putchar('\n');
    }
    return 0;
}
