#include<bits/stdc++.h>
#define left index*2
#define right index*2+1
 
using namespace std;
 
long long marked[4500001];
 
inline void update(int index, int tl, int tr, int l, int r, long long val) {
    
    if(tl > r || tr < l)
        return;
        
    if(tl == l && tr == r) {
        marked[index] += val;
        return;
    }
    
    int mid = (tl+tr)>>1;
    
    if(r <= mid) {
        update(left, tl, mid, l, r, val);
    }
    else if(l > mid) {
        update(right, mid+1, tr, l, r, val);
    }
    else {
        update(left, tl, mid, l, mid, val);
        update(right, mid+1, tr, mid+1, r, val);
    }
}
 
int main() {
    
    int n,m,p,u,v;
    long long c,k;
    char type;
    
    scanf("%d %d %lld",&n,&m,&c);
    
    while(m--) {
        
        while(isalpha(type=getchar()) == false);
        
        if(type == 'S') {
            //puts("type S");
            scanf("%d%d%lld",&u,&v,&k);    
            update(1, 1, n, u, v, k);
        }   
        
        else {
            //puts("Type Q");
            scanf("%d",&p);
            
            
            //querying here.
            int low = 1, high = n, index = 1;
            long long temp = 0;
            int mid; 
            
            while(low!=high) {
                
                temp += marked[index];
                mid = (low+high)>>1;
                index<<=1;
                
                if(p<=mid) {
                    high = mid;
                }
                
                else {
                    index++;
                    low = mid + 1;
                }
            }
            temp += marked[index];
            
            printf("%lld\n",temp+c);
        }
    }
    
    return 0;
}
