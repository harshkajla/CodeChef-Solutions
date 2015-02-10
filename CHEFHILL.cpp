#include<bits/stdc++.h>
#define left index*2
#define right index*2+1
using namespace std;
int tree[300000];
int a[100001];
void buildtree(int index, int l, int r)
{
    if(l == r)
    {
        tree[index] = a[l];
        return;
    }
    
    int mid = (l + r) >> 1;
    
    buildtree(left, l, mid);
    buildtree(right, mid + 1, r);
    
    tree[index] = max(tree[left], tree[right]);    
}
int findmax(int index, int l, int r, int tl, int tr)
{
    if(l > r)
        return 0;
        
    if(tl == l && tr == r)
        return tree[index];
        
    int mid = (tl + tr) >> 1;
    
    if(r <= mid)
        return findmax(left, l, r, tl, mid);
    
    else if(l > mid)
        return findmax(right, l, r, mid + 1, tr);
        
    return max(findmax(left, l, mid, tl, mid), findmax(right, mid + 1, r, mid + 1, tr));
}
int main()
{
    int n, q, x, y;
    
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
        
    buildtree(1, 0, n - 1);
    scanf("%d",&q);
    
    while(q--)
    {
        scanf("%d%d",&x,&y);
        x--;y--;
        int m = findmax(1, x+1, y-1, 0, n-1);
        
        if(m > a[x])
            puts("NO");
            
        else puts("YES");
    }    
    
    return 0;
}
