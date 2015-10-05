#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        int h=(str[0]-'0')*10+(str[1]-'0');
        int m=(str[3]-'0')*10+(str[4]-'0');
        
        if(h>=12)h-=12;
        
        //finding angle of hour hand..
        double hangle = 0.5 * (h*60 + m);
        
        while(hangle>=360.0)hangle-=360.0;
        
        //finding angle of minute hand..
        double mangle = m*6.0;
        
        double diff=abs(hangle-mangle);
        diff=min(360.0-diff,diff);
        double epsilon=1e-9;
        
        int f=0;
        while(diff!=0)
        {
            diff-=5.0;
            if(diff<0)
            {
                f=1;break;
            }
        }
        if(f==0)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
