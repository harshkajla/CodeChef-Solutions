#include<bits/stdc++.h>
using namespace std;
int init[1001][1001];
int temp[1001][1001];
int fin[1001][1001];
bool rows[1001],cols[1001];
bool rowswap[1001],colswap[1001];
int main()
{
        int t,n;
        scanf("%d",&t);
        
        while(t--)
        {
                scanf("%d",&n);
                
                memset(rows,false,sizeof rows);
                memset(cols,false, sizeof cols);
                memset(rowswap,false,sizeof cols);
                memset(colswap, false, sizeof cols);
                
                bool same = true;
                for(int i=0;i<n;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                scanf("%d",&init[i][j]);
                                temp[i][j]=init[i][j];
                        }
                }
                
                
                for(int i=0;i<n;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                scanf("%d",&fin[i][j]);
                                if(fin[i][j]!=init[i][j])
                                        same = false;
                        }
                }
                
                //if they're the same, save the pain.
                if(same)
                {
                        puts("0");
                        continue;
                }
                
                //first i dont change the first row.
                //comparing the first rows.
                
                for(int i=0;i<n;i++)
                {
                        if(init[0][i]!=fin[0][i])
                                colswap[i]=true;
                }
                
                //now comparing rest of the rows to decide which all rows to invert.
                for(int i=1;i<n;i++)
                {
                        if(colswap[0])
                                rowswap[i]=(init[i][0]==fin[i][0]);
                                
                        else
                                rowswap[i] = (init[i][0]!=fin[i][0]);
                }
                
                same = true;
                //now making the changes and comparing.
                for(int i=0;i<n;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                if(rowswap[i])
                                        temp[i][j]=1-temp[i][j];
                                if(colswap[j])
                                        temp[i][j]=1-temp[i][j];
                                        
                                if(temp[i][j]!=fin[i][j])
                                {
                                        same = false;
                                        break;
                                }
                        }
                        if(same==false)
                                break;
                }
                
                //now inverting the first row.
                rows[0]=true;
                for(int i=0;i<n;i++)
                {
                        cols[i]=(init[0][i]==fin[0][i]);
                }
                
                //now comparing the rest of rows.
                for(int i=1;i<n;i++)
                {
                        if(cols[0])
                                rows[i] = (init[i][0]==fin[i][0]);
                        
                        else
                                rows[i] = (init[i][0]!=fin[i][0]);
                                
                }
                
                //implementing the changes.
                bool same1 = true;
                for(int i=0;i<n;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                if(rows[i])
                                        init[i][j]=1-init[i][j];
                                if(cols[j])
                                        init[i][j]=1-init[i][j];
                                        
                                if(init[i][j]!=fin[i][j])
                                        same1 = false;
                        }
                        if(!same1)
                                break;
                }
        
                int cnt1=0,cnt2=0,cnt11=0,cnt22=0;
                if(same)
                {
                        cnt1=cnt2=0;
                        for(int i=0;i<n;i++)
                        {
                                cnt1+=rowswap[i];
                                cnt2+=colswap[i];
                        }
                }
                
                if(same1)
                {
                        cnt11=cnt22=0;
                        for(int i=0;i<n;i++)
                        {
                                cnt11+=rows[i];
                                cnt22+=cols[i];
                        }
                }
                
                if(!same1 || (same && same1 && (cnt1+cnt2) <= (cnt11+cnt22)))
                {
                        if(!same)
                        {
                                puts("-1");
                                continue;
                        }
                        
                        else
                        {
                                printf("%d\n",cnt1);
                                for(int i=0;i<n;i++)
                                        if(rowswap[i])
                                                printf("%d\n",i);
                                      
                                printf("%d\n",cnt2);
                                for(int i=0;i<n;i++)
                                        if(colswap[i])
                                                printf("%d\n",i);
                        }
                }
                
                else
                {
                        printf("%d\n",cnt11);
                        for(int i=0;i<n;i++)
                                if(rows[i])
                                        printf("%d\n",i);
                                        
                        printf("%d\n",cnt22);
                        for(int i=0;i<n;i++)
                                if(cols[i])
                                        printf("%d\n",i);
                }
        }
        
        return 0;
}
