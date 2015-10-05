#include<bits/stdc++.h>
#define lol long long
using namespace std;
lol ans[123456];
int lim[123456],z[123456],o[123456];
char str[123456];
lol s(int x)
{
    lol xx = static_cast<lol>(x);
    return xx*(xx+1)/2;
}
int main()
{
    int t,n,k,q,l,r,ind0,ind1,index;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&q);
        
        scanf("%s",str);
        
        //preprocessing part..
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                z[i] = (str[i]=='0');
                o[i] = (str[i]=='1');
            }
            
            else
            {
                z[i] = z[i-1] + (str[i]=='0');
                o[i] = o[i-1] + (str[i]=='1');
            }
        }
        
        //now that i've counted the 0s and 1s..time for binary search.
        for(int i=0;i<n;i++)
        {
            //find index of atmost k 0s.
            if(str[i]=='0')
            {
                ind0 = upper_bound(z+i,z+n,z[i]+k-1)-z-1;
                ind1 = upper_bound(o+i,o+n,o[i]+k)-o-1;
                lim[i] = min(ind0,ind1);
            }
            
            else
            {
                ind0 = upper_bound(z+i,z+n,z[i]+k)-z-1;
                ind1 = upper_bound(o+i,o+n,o[i]+k-1)-o-1;
                lim[i] = min(ind1,ind0);
            }
            
            if(i==0)
            ans[i]=lim[i]-i+1;
            
            else ans[i]=ans[i-1] + lim[i]-i+1;
            
            //printf("i=%d..lim[%d]=%d\n",i,i,lim[i]);
        }        
        
        while(q--)
        {
            scanf("%d %d",&l,&r);
            l--;r--;
            
            //find no of indices in [l,r] such that their lim[] value <=r.
            index = upper_bound(lim+l,lim+r,r)-lim-1;
            
            //for the rest of them from [index+1..r] the limit is r.
            //i.e. summation (r-i+1)..for each i in [index+1..r].
            lol offset = 0;
            
            offset = r-index;
            offset*=r+1;
            offset -= s(r)-s(index);
            
            //printf("index=%d\n",index);
            
            //find sum of lim[l]..lim[index].
            if(l==0)
            {
                printf("%lld\n",ans[index]+offset);
            }
            
            else
            {
                printf("%lld\n",ans[index] - ans[l-1]+offset);
            }
        }
    }
}
