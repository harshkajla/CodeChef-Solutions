#include<stdio.h>
#include<algorithm>
using namespace std;
int lx,ly,lca,llca,inverts;
int blacks(int x, int y, int lx, int ly)
{
    int bx,by;
    //its certain that x>y.
    if(inverts%2==0)
    {
        bx=(lx+1)/2;
        by=(ly+1)/2;
        
        return bx-by;
    }
    
    else
    {
        bx=lx>>1;
        by=ly>>1;
        
        return bx-by;
    }
}
int reds(int x, int y, int lx, int ly)
{
    //it is certain that x>y.
    return (lx-ly)-blacks(x,y,lx,ly);
}
void calc(int x, int y)
{
    int tx,ty;
    
    tx=x;ty=y;
    
    lx=0;
    while(tx)
    {
        tx>>=1;lx++;
    }
    
    ly=0;
    while(ty)
    {
        ty>>=1;ly++;
    }
    
    tx=x;ty=y;lca=1;
    while(tx&&ty)
    {
        if(tx==ty)
        {
            lca=tx;break;
        }
        
        if(tx>ty)tx>>=1;
        else ty>>=1;
    }
    
    tx=lca;llca=0;
    while(tx)
    {
        tx>>=1;llca++;
    }
}
int main()
{
    int q,x,y,ans;
    
    char Q[20];
    scanf("%d",&q);
    
    inverts=0;
    while(q--)
    {
        scanf("%s",Q);
        
        if(Q[1]=='i')
        {
            inverts++;
            continue;
        }
        
        scanf("%d%d",&x,&y);
        if(x<y)swap(x,y);
        calc(x,y);
        
        ans=0;
        if(Q[1]=='b')
        {
            ans=blacks(x,lca,lx,llca)+blacks(y,lca,ly,llca);
            
            if(inverts%2==0)
            ans+=(llca%2==1);
            
            else ans+=(llca%2==0);
        }
        
        else
        {
            ans=reds(x,lca,lx,llca)+reds(y,lca,ly,llca);
            
            if(inverts%2==0)
            ans+=(llca%2==0);
            
            else ans+=(llca%2==1);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
