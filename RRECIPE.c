#include<stdio.h>
#include<string.h>
#define M 10000009
int read(){
int t=0;
char c;
c=getchar_unlocked();
while(c<'0' || c>'9')
c=getchar_unlocked();
while(c>='0' && c<='9'){
t=(t<<3)+(t<<1)+c-'0';
c=getchar_unlocked();
}
return(t);
}
int main()
{
    int t,begin,end,l,f,i;
    int ans;
    char str[1000001];
    t=read();
    while(t--)
    {
        for(i=0;i<1000001;i++)str[i]='\0';
        i=0;
        while((str[i++]=getchar_unlocked())!='\n');
        l=i-1;
        begin=0;end=l-1;f=0;ans=1;
        //printf("begin=%d end=%d\n",begin,end);
        while(begin<=end)
        {
            if(str[begin]!='?' && str[end]!='?')
            {
                if(str[begin]!=str[end])
                {
                    ans=0;break;
                }
            }
            else if(str[begin]=='?' && str[end]=='?')
            {
                ans=((ans<<4) + (ans<<3) +(ans<<1))%M;
            }
            begin++;end--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
