#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&x);
        if(x==2||x==17)
        {
            puts("Mike");
            continue;
        }
        
        else if(x==16 || x==34||x==289)
        {
            puts("Tom");
            continue;
        }
        
        bool prime=true;
        for(int i=2;i*i<=x;i++)
        {
            if(x%i==0)
            {
                prime=false;
                break;
            }
        }
        
        if(!prime)
            puts("Mike");
        
        else
            puts("Tom");
    }
    
    return 0;
}
