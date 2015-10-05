#include<bits/stdc++.h>
using namespace std;
 
long long s(long long n)
{
    return n*(n+1)/2;
}
long long K[500001];
int main()
{
    long long t,n,k,temp;
    long long sn,sk,missing;
 
    cin>>t;
 
    while(t--)
    {
        cin>>n>>k;
 
        sn = n*(n+1)/2;
 
        if(k==0)
        {
            if(sn%2==1)
                puts("Mom");
            else puts("Chef");
 
            continue;
        }
        
        for(int i=0;i<k;i++)
        {
            cin>>K[i];
        }
        
        sort(K,K+k);
        sk=0;missing=-1;
        bool p[5]={false,false,false,false,false};
        for(int i=0;i<k;i++)
        {
            sk+=K[i];
            if(missing == -1 && ((s(K[i]) - sk + 1) == K[i]))
            {
                missing = K[i];
                break;
            }
            p[K[i]]=true;
        }
        
        if(missing!=-1)
        {
            if(missing%2==1)
            puts("Chef");
            else puts("Mom");
        }
    
        else
        {
            long long ans = sn-sk+1;
            if(ans%2==1)
            puts("Chef");
            else puts("Mom");
        }
    }
 
    return 0;
}
