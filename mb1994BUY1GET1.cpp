#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
stack<int> st;
long long a[100001],sum[100001],dp[100001];
int opening[1000001];
char str[100001];
inline long long sum_(int i, int j)
{
    if(i==0)
        return sum[j];
    else return sum[j]-sum[i-1];
}
inline bool isopen(char ch)
{
    return ch=='('||ch=='{'||ch=='['||ch=='<';
}
inline char openof(char ch)
{
    if(ch==')')return '(';
    if(ch=='}')return '{';
    if(ch==']')return '[';
    if(ch=='>')return '<';
}
int main()
{
    int t,n;
    
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",str);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            opening[i]=-1;
        }
        
        
        //for each starting bracket..find its matching closing bracket..
        //if i do this way..ill find ending points of all brackets within the above bracket expression..
        
        while(!st.empty())st.pop();
        
        for(int i=0;i<n;i++)
            opening[i]=-1;
        
        for(int i=0;i<n;i++)
        {
            //if this is an opening one..
            if(isopen(str[i]))
            {
                st.push(i);
            }
            else
            {
                //if its closing bracket matched..
                if(st.size() && (str[st.top()] == openof(str[i])))
                {
                    opening[i]=st.top();
                    st.pop();
                }
                else
                {
                    //this means for all opening brackets in stack..they dont have a closing index..
                    st.push(i);
                }
            }
        }
        
        //storing cumulative sums..
        long long ans=0;
        
        sum[0]=a[0];
        
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+a[i];
            dp[i]=0;
        }
        
        for(int i=1;i<n;i++)
        {
            if(!isopen(str[i]) && opening[i]!=-1)
            {
                dp[i]=max(dp[i],dp[opening[i]-1]+sum_(opening[i],i));
            }
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
