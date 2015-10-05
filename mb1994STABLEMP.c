#define _CRT_DISABLE_PERFCRIT_LOCKS
    #include<stdio.h>
    #define ptc(x) putchar_unlocked(x)
    short winner_against[10001];
    inline short read_int()
    {
    register short noRead=0,isneg=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked()){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    if(isneg) noRead = -noRead;
    return noRead;
    }
    inline int red_int()
    {
    register int noRead=0,isneg=0;
    register char p=getchar_unlocked();
    for(;p<48 || p>57;p=getchar_unlocked()){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    if(isneg) noRead = -noRead;
    return noRead;
    };
    inline void fastWrite(short a)
    {
    char snum[6];
    register short i=0;
    do
    {
    snum[i++]=a%10+48;
    a=a/10;
    }
    while (a);
    i=i-1;
    while (i>=0)
    putchar_unlocked(snum[i--]);
    putchar_unlocked('\n');
    }
    //find chef with dish x..
    inline short findchef(short x)
    {
    if((winner_against[x]==x) || (winner_against[winner_against[x]]==winner_against[x]))
    return winner_against[x];
    else
    {
    winner_against[x]=winner_against[winner_against[x]];
    return findchef(winner_against[x]);
    }
    }
int main()
{
    int score[10001];
    register short n,i,way,q,x,y,t;
    t=read_int();
    while(t--)
    {
    n=read_int();
    for(i=1;i<=n;i++)
    {
    score[i]=red_int();
    winner_against[i]=i;
    }
    q=read_int();
    while(q--)
    {
    way=read_int();
    if(way==0)
    {
    x=read_int();
    y=read_int();
    //chefs of dish x and dish y combat..
    x=findchef(x);
    y=findchef(y);
    if(x==y)
    {
    fputs("Invalid query!\n", stdout);
    }
    else
    {
    if(score[x]>score[y])
    {
    winner_against[y]=x;
    }
    else if(score[y]>score[x])
    {
    winner_against[x]=y;
    }
    }
    }
    else
    {
    x=read_int();
    fastWrite(findchef(x));
    }
    }
    }
    return 0;
    }
