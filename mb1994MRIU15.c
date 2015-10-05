#include<stdio.h>
#define lol long long
lol sz[50], cz[50];
int main()
{
    int t,s,c,k,posc,ccnt,i;
    
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d%d",&s,&c,&k);
        posc=-1;ccnt=0;
        
        for(i=1;i<=s;i++)
            sz[i] = (1ll<<i)+1;
        
        for(i=1;i<=c;i++)
            cz[i] = 1ll<<i;
        
        lol ans=0,temp=0,coss=0;
        
        if(k==1)
        {
            //summing up the sin functions.
            lol ans=0,temp=0;
            for(i=1;i<=s;i++)
            {
                ans+=sz[i]-temp;
                temp += sz[i]-temp;
            }
            
            //summing up the cos functions.
            if(c>=s)
            {
                for(i=s;i<=c;i++)
                    ans+=cz[i];
            }
            
            printf("%lld\n",ans);
            continue;
        }
        
        temp=0;
        lol coscnt=0;
        for(i=1;i<=s;i++)
        {
            //first check if sin-sin interactions are enough.
            if(s-i+1>=k)
            {
                ans += sz[i]-temp;
                temp += sz[i]-temp;
                coscnt=0;
            }
            
            else
            {
                //include cos functions as well.
                //number of cos functions=i-1.
                if(s-i+2>=k)
                {
                    ans += coscnt;
                    coscnt=0;
                }
                
                else
                {
                    break;
                }
            }
            
            if(i<=c)
                coscnt+=cz[i];
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
