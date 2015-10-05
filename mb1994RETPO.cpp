#include<bits/stdc++.h>
#define left index*2
#define right index*2+1
#define lol long long
using namespace std;
 
int z[100001], o[100001];
int n,k;
string str;
lol tree[456789];
lol find(int index, int tl, int tr, int l, int r)
{
    
    if(tl==l && tr==r)
    {
    
        if(tree[index]!=-1)
            return tree[index];
            
        if((r-l+1) <= k)
        {
            lol x=r-l+1;
            x*=x+1;
            x>>=1;
            
            tree[index] = x;
            return x;
        }
        
        int mid = (tl+tr)>>1;
        lol a = find(left, tl, mid, l, mid);
        lol b= find(right, mid+1, tr, mid+1, r);
        
        a+=b;
        b=0;
        int c0=0,c1=0;
        
        for(int i=mid;i>=l;i--)
        {
            int j=mid+1;
            
            if(j>r || (j-i+1)>2*k)break;
            
            if(i==mid)
            {
                c0=z[mid];
                c1=o[mid];
            }
            
            else
            {
                c0+=(str[i]=='0');
                c1+=(str[i]=='1');
            }
            
            //find min index where either 0s sum up to k-c0 or 1s sum up tp k-c1.
            
            int zff,off;
            if(i==mid)
            {
                zff = c0+k-(str[i]=='0');
                off = c1+k-(str[i]=='1');
            }
            else
            {
                zff-=str[i]=='0';
                off-=str[i]=='1';
            }
            
            //printf("i=%d..c0=%d..z[i=%d]=%d..zff=%d\n",i,c0,i,z[i],zff);
            //printf("i=%d..c1=%d..o[i=%d]=%d..off=%d\n",i,c1,i,o[i],off);
            
            int aa = upper_bound(z+j,z+r+1,zff)-(z+j)-1;
            int ba= upper_bound(o+j,o+r+1,off)-(o+j)-1;
                
            //printf("mid+1=%d r=%d aa=%d, bb=%d\n",mid+1,r,aa+1,ba+1);
            b += min(aa+1,ba+1);
        }
        
        a+=b;
        tree[index] = a;
        
        return tree[index];
    }
    
    else
    {
        int mid = (tl+tr)>>1;
        
        if(r<=mid)
            return find(left, tl, mid, l, r);
            
        else if(l>mid)
            return find(right, mid+1, tr, l, r);
            
        //printf("finding in else..[%d,%d,%d]\n",l,mid,r);
        
        lol a = find(left, tl, mid, l, mid);
        lol b= find(right, mid+1, tr, mid+1, r);
        
        a+=b;
        b=0;
        int c0=0,c1=0;
        
        for(int i=mid;i>=l;i--)
        {
            int j=mid+1;
            
            if(j>r || (j-i+1)>2*k)break;
            
            if(i==mid)
            {
                c0=z[mid];
                c1=o[mid];
            }
            
            else
            {
                c0+=(str[i]=='0');
                c1+=(str[i]=='1');
            }
            
            //find min index where either 0s sum up to k-c0 or 1s sum up tp k-c1.
            
            int zff,off;
            if(i==mid)
            {
                zff = c0+k-(str[i]=='0');
                off = c1+k-(str[i]=='1');
            }
            else
            {
                zff-=str[i]=='0';
                off-=str[i]=='1';
            }
            
            //printf("i=%d..c0=%d..z[i=%d]=%d..zff=%d\n",i,c0,i,z[i],zff);
            //printf("i=%d..c1=%d..o[i=%d]=%d..off=%d\n",i,c1,i,o[i],off);
            
            int aa = upper_bound(z+j,z+r+1,zff)-(z+j)-1;
            int ba= upper_bound(o+j,o+r+1,off)-(o+j)-1;
                
            //printf("mid+1=%d r=%d aa=%d, bb=%d\n",mid+1,r,aa+1,ba+1);
            b += min(aa+1,ba+1);
        }
        
        a+=b;
        tree[index] = a;
        return a;
    }
}
 
int main()
{
    int t,q,l,r;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&q);
        
    
        for(int i=0;i<456789;i++)
            tree[i] = -1;
        
        cin>>str;
        z[0]=str[0]=='0';o[0]=str[0]=='1';
        for(int i=1;str[i];i++)
        {
            z[i] = z[i-1] + (str[i] == '0');
            o[i] = o[i-1] + (str[i] == '1');
        }
            
        while(q--)
        {
            scanf("%d%d",&l,&r);
            
            printf("%lld\n",find(1,0,n-1,l-1,r-1));
        }
    }
    
    return 0;
}
