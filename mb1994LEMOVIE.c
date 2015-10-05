#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked();
 
 int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
 
 
int main()
{
    int t;
    t=read_int();
 
    while(t--)
    {
        int m,n,a,b,i,count=0,exchanges=0;
 
        n=read_int();
        m=read_int();;
 
        int matrix[101][101],j,set[101],visited[101][101];
 
        for(i=1;i<=100;i++)
            set[i]=1;
 
 
        for(i=1;i<=100;i++)
        {
            for(j=1;j<=100;j++)
            {
            matrix[i][j]=0;
            visited[i][j]=0;
            }
        }
 
        for(i=1;i<=m;i++)
        {
            a=read_int();
            b=read_int();
            matrix[a][b]=1;
            matrix[b][a]=1;
        }
        int temp[101],temp2[101];
 
        for(i=0;i<=100;i++)
        {
           	temp[i]=0;
           	temp2[i]=0;
        }
 
        int k=0;
 
        if(n%2==1)
        {
            printf("NO\n");
            continue;
        }
 
        else
        {
           i=1;
           for(j=1;j<=n;j++)
           {
             if(set[i])
             {
             	
                if(matrix[i][j]==1 && visited[i][j]==0)
                {
                  if(set[j])
                  {
                 
                  if(i==1)
                  {
                  matrix[i][j]=0;
                  matrix[j][i]=0;
                  }
                  visited[i][j]=1;
                  count++;
                  set[j]=0;
                  set[i]=0;
                  temp2[k]=i;
                  temp[k]=j;
                  k++;
                  i++;
                  j=0;
                  exchanges=0;
                  }
 
                  else
                    exchanges++;
                }
 
                else
                    exchanges++;
             }
 
             else if(set[i]==0)
             {
                 i++;
                 j=0;
                 exchanges=0;
                 continue;
             }
 
                if(exchanges==n)
                {
                    count--;
 
                    exchanges=0;
                    int p;
                   
                    for(p=1;p<=n;p++)
                    {
                        if(visited[i][p]==1 && matrix[i][p]==1)
                            visited[i][p]=0;
                           
                    }
                    /*printf("%d %d->\n",i,j);*/
                    j=0;
                    k--;
                    i=temp2[k];
                    set[temp[k]]=1;
                    set[temp2[k]]=1;
                }
 
                if(count==(n/2))
                {
                 printf("YES\n");
                 break;
                }
 
                else if(count<0)
                {
                    printf("NO\n");
                    break;
                }
           }
        }
    }
 
    return 0;
}
