#include<bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
vector<long long> a;
long long trace[100];
long long len;
 
bool subsetSum(long long sum, long long i, long long k)
{
    //cout<<"ssum("<<sum<<" "<<i<<" "<<k<<")"<<endl;
    if(sum==0)
    {
        //cout<<"sum made by:"<<endl;
        for(int i=0;i<k;i++)
        {
            //cout<<trace[i]<<" ";
            a.erase(find(a.begin(),a.end(),trace[i]));
        }
        //cout<<endl;
        
        len-=k;
        
        return true;
    }
    
    
    else if(sum<0 || i<0)
    return false;
    
//    return subsetSum(sum-a[i],i-1) || subsetSum(sum,i-1);
    if(subsetSum(sum,i-1,k))
    return true;
    
    
    if(a[i]<=sum)
    {
        trace[k]=a[i];
        if(subsetSum(sum-a[i],i-1,k+1))
        return true;
    }
}
bool allzeros()
{
    bool res=true;
    
    for(int i=0;i<a.size();i++)
    res=res&&(a[i]==0);
    
    return res;
}
int main()
{
    long long t,n,k,x,s;
    
    cin>>t;
    
    while(t--)
    {
        cin>>n>>k;
        
        len=n;
        a.clear();
        
        s=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.pb(x);
            s+=x;
        }
        
        if(s%k!=0)
        {
            puts("no");
            continue;
        }
        
        if(s==0)
        {
            if(n>=k)
            puts("yes");
            
            else puts("no");
            
            continue;
        }
        
        s/=k;
        bool res=true;
 
        int i=0;
        int prevlen=len;
        //cout<<"sum="<<s<<endl;
        while(i<k && len!=0)
        {
           res=res&&subsetSum(s,len-1,0);
           if(!res)
           break; 
           i++;
        }
        
        if(res && (len==0 || allzeros()))
        puts("yes");
        
        else puts("no");
    }
 
    return 0;
}
