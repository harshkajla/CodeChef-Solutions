#include<bits/stdc++.h>
using namespace std;
int br[101],str[101];
bool stable(int k)
{
    stack<int> st;
    
    for(int i=0;i<k;i++)
    {
        //if this is an opening bracket.
        if(str[i]<0)
        st.push(str[i]);
        
        else
        {
            if(st.empty() || st.top()!=-str[i])
            return false;
            
            st.pop();
        }
    }
    
    if(!st.empty())
    return false;
    
    return true;
}
int main()
{
    int n,ans=0;
    
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>br[i];
    }
    
    int comb = 1<<n;
    
    for(int i=0;i<comb;i++)
    {
        int bitno=0;
        int tmp=i;
        int k=0;
        
        while(tmp)
        {
            if(tmp&1)
            str[k++]=br[bitno];
            
            bitno++;
            tmp>>=1;
        }
        
        if(stable(k))
        ans++;
    }
    
    cout<<ans<<endl;
    return 0;
}
