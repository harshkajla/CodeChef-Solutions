#include<bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> ones;
vector<lol> twos;
lol ans[200001];
int main()
{
    int n,a;
    lol b;
    lol wt = 0;
    
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d %lld",&a,&b);
        wt += a;
        
        if(a==1)
            ones.push_back(b);
        else
            twos.push_back(b);
    }
    
    sort(ones.begin(), ones.end());
    sort(twos.begin(), twos.end());
    
    vector<lol> O = ones;
    vector<lol> T = twos;
    
    ans[0] = 0;
    for(int i = 2; i <= wt; i+=2)
    {
        //both unavailable.
        if(O.size() == 0 && T.size() == 0)
        {
            ans[i] = ans[i-2];
            continue;
        }
        
        int x=0,y=0,flag=1;
        if(O.size() >= 2)
        {
            x = O.back() + O[O.size()-2];
        }
        else if(O.size() == 1)
        {
            flag = 2;
            x = O.back();
        }
        
        if(T.size() != 0)
        {
            y = T.back();
        }
        
        if(y>=x)
        {
            T.pop_back();
            ans[i] = ans[i-2] + y;
        }
        
        else
        {
            if(flag == 1)
            {
                O.pop_back();
                O.pop_back();
                ans[i] = ans[i-2] + x;
            }
            
            else
            {
                O.pop_back();
                ans[i] = ans[i-2] + x;
            }
        }
    }
    
    O = ones;
    T = twos;
    
    if(O.size() >= 1)
    {
        ans[1] = O.back();
        O.pop_back();
    }
    
    else
        ans[1] = 0;
    
    for(int i = 3; i <= wt; i+=2)
    {
        //both unavailable.
        if(O.size() == 0 && T.size() == 0)
        {
            ans[i] = ans[i-2];
            continue;
        }
        
        int x=0,y=0,flag=1;
        if(O.size() >= 2)
        {
            x = O.back() + O[O.size()-2];
        }
        else if(O.size() == 1)
        {
            flag = 2;
            x = O.back();
        }
        
        if(T.size() != 0)
        {
            y = T.back();
        }
        
        if(y>=x)
        {
            T.pop_back();
            ans[i] = ans[i-2] + y;
        }
        
        else
        {
            if(flag == 1)
            {
                O.pop_back();
                O.pop_back();
                ans[i] = ans[i-2] + x;
            }
            
            else
            {
                O.pop_back();
                ans[i] = ans[i-2] + x;
            }
        }
    }
    
    for(int i = 1; i <= wt; i++)
    printf("%lld ", ans[i]);
    
    puts("");
    return 0;
    
}
