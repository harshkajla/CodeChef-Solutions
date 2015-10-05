#include<bits/stdc++.h>
#define lol long long
#define mp make_pair
#define gc getchar_unlocked
using namespace std;
 
int A[100001];
int mx[100001],my[100001],xx[100001],yy[100001];
int M[100001][17];
int logval[100001];
#define gc getchar_unlocked
inline int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
inline void process2(int N)
  {
      int i, j;
   
  //initialize M for the intervals with length 1
      for (i = 0; i < N; i++)
          M[i][0] = i;
      int tt=1;
  //compute values from smaller to bigger intervals
      for (j = 1; (tt<<=1) <= N; j++)
          for (i = 0; i + tt - 1 < N; i++)
              if (A[M[i][j - 1]] >= A[M[i + (tt>>1)][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (tt>>1)][j - 1];
  }  
int main()
{
    int N,a,x,b,y,m;
    int length,times_more;
    
    lol ans,temp;
    
    scanf("%d",&N);
    int curval=-1,nextpow2=1;
    for(int i=0;i<N;i++)
    {
        A[i]=read_int();
        if((i+1)&i)
        {
            logval[i+1]=curval;
        }
        
        else
        {
            logval[i+1]=++curval;
        }
    }
        
    
  process2(N);    
   m=read_int();x=read_int();y=read_int();
   
    //precomputing x mod values..
    mx[x]=true;
    xx[0]=x;int i=1;
    int sx=0,sy=0;
    
    while(1)
    {
      //calculate the next x..
      xx[i]=xx[i-1]+7;
      while(xx[i]>=N-1)xx[i]-=N-1;
      
      //see if this has already occured..
      if(mx[xx[i]])
      {
        sx=i;break;
      }
      
      else
      {
        mx[xx[i]]=true;
        i++;
      }
    }
    
    //precomputing x mod values..
    my[y]=true;
    yy[0]=y;i=1;
    while(1)
    {
      //calculate the next x..
      yy[i]=yy[i-1]+11;
      while(yy[i]>=N)yy[i]-=N;
      
      //see if this has already occured..
      if(my[yy[i]])
      {
        sy=i;break;
      }
      
      else
      {
        my[yy[i]]=true;
        i++;
      }
    }
    
    //keep one constant..here x.
    ans=0;
    int pos,k,index,tot=0;
    for(int i=0;i<sy;i++)
    {
      pos=i+1;y=yy[i];index=i;
      while(pos<=m)
      {
        a=y;
        b=xx[index];
        
        if(a>b)swap(a,b);
        
        k=logval[b-a+1];
        temp=max(A[M[a][k]], A[M[b-(1<<k)+1][k]]);
        ans+=temp;
        
        pos=pos+sy;
        index=index+sy;
        while(index>=sx)index-=sx;
        tot++;
        
        if(tot==m)break;
      }
    }
    /*
    int px=0,py=0,k;
    for(int i=1;i<=m;i++)
    {
        if(px==sx)
          px=0;
        
        if(py==sy)
            py=0;
            
        a=xx[px++];
        b=yy[py++];
        
        if(a>b)a=(a+b)-(b=a);
            
        k=logval[b-a+1];
        ans+=max(A[M[a][k]], A[M[b-(1<<k)+1][k]]);
    }*/
    printf("%lld\n",ans);
    return 0;
}
