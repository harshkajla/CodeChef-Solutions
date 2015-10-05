#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
    int big=0,small=0,num=0;
    
    cin>>str;
    if(str.size()<5)
    {
        puts("NO");
        return 0;
    }
    for(int i=0;str[i];i++)
    {
        if(isalpha(str[i]))
        {
            if(str[i]>='A' && str[i]<='Z')
            {
                big=1;
            }
            else small=1;
        }
        else if(isdigit(str[i]))
        {
            num=1;
        }
    }
    if(big+small+num!=3)
    {
        puts("NO");
        return 0;
    }
    else puts("YES");
    return 0;
}
