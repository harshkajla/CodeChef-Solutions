#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<string.h>
#define mod 1000000007
using namespace std;
vector<int> persons[101];
int comb,maxtid;
long long dp[1025][101];
inline bool issetbit(int mask, int index)
{
        //check if bit no "index" from right is set.
        return (mask>>index)&1;
}
inline int setbit(int mask, int index)
{
        //set bit no "index" from right.
        return mask | (1<<(index));
}
long long calc(int mask, int tid)
{  
    //printf("doing calc(%d, %d)\n",mask,tid);
    if(mask==comb-1)
    return 1;
    
    else if(tid>maxtid)
    return 0;
    
    //first see if its already been calculated..
    if(dp[mask][tid]!=-1)
    return dp[mask][tid];
    
    //first i dont allocate this tshirt at all.
    long long ans = calc(mask, tid+1);
    if(ans>mod)
    ans%=mod;
    
    //now time to allocate shirt "tid"
    for(int i=0;i<persons[tid].size();i++)
    {
        //if this person already is allocated a shirt.
        if(!issetbit(mask,persons[tid][i]))
        {
            //try giving this tshirt to him..
            ans+=calc(setbit(mask, persons[tid][i]), tid+1);
            
            if(ans>mod)
            ans%=mod;
        }
    }
    
    return dp[mask][tid]=ans;
}
int main()
{
    int t,n;
    string str;
    int temp;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        getchar();
        
        for(int i=0;i<=100;i++)
        persons[i].clear();
        
        comb=1<<n;
        
        for(int i=0;i<n;i++)
        {
            getline(cin, str);
            //cout<<str<<endl;
            stringstream ss(str);
            
            maxtid=0;
            while(ss>>temp)
            {
                persons[temp].push_back(i);
            }
        }
        
        maxtid=100;
        for(int i=0;i<=comb;i++)
        {
            for(int j=0;j<=maxtid;j++)
            dp[i][j]=-1;
        }
        
        cout<<calc(0,1)<<endl;
    }
    
    return 0;
}
