#include<bits/stdc++.h>
#define lol long long
using namespace std;
char str[100001];
int main()
{
    int t,type,og,eg,ob,eb;
    scanf("%d",&t);
    
    
    while(t--)
    {
        og=eg=ob=eb=0;
        vector<lol> BE,BO,GE,GO;
        scanf("%d",&type);
        scanf("%s",str);
        
        for(int i=0;str[i];i++)
        {
            if(str[i]=='G')
            {
                if(i&1)
                {
                    og++;
                    GO.push_back(i);
                }
                else
                {
                    eg++;
                    GE.push_back(i);
                }
            }
            
            else
            {
                if(i&1)
                {
                    ob++;
                    BO.push_back(i);
                }
                else
                {
                    eb++;
                    BE.push_back(i);
                }
            }
        }
        
        if(ob+eb==eg+og)
        {
            if(type==0)
                printf("%d\n",min(ob,eb));
                
            else
            {
                lol cost1=0,cost2=0;
                //either start with B..
                for(int i=0;i<BO.size();i++)
                {
                    cost1 += abs(BO[i]-GE[i]);
                }
                
                //or with G..
                for(int i=0;i<GO.size();i++)
                {
                    cost2 += abs(BE[i]-GO[i]);
                }
                
                printf("%lld\n",min(cost1,cost2));
            }
        }
        
        else if(ob+eb==og+eg+1)
        {
            if(type==0)
                printf("%d\n",ob);
                
            else
            {
                //start with B..
                lol cost1=0;
                //either start with B..
                for(int i=0;i<BO.size();i++)
                {
                    cost1 += abs(BO[i]-GE[i]);
                }
                printf("%lld\n",cost1);
            }
        }
        
        else if(ob+eb==eg+og-1)
        {
            if(type==0)
                printf("%d\n",og);
            
            else
            {
                lol cost1=0;
                //start with G..
                for(int i=0;i<BE.size();i++)
                {
                    cost1 += abs(BE[i]-GO[i]);
                }
                
                printf("%lld\n",cost1);
            }
        }
        
        else
        {
            puts("-1");
        }
    }
    
    return 0;
}
