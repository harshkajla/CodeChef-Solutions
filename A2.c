#include<stdio.h>
    #define read(n) \
    {\
    n = 0;\
    \
    while ((c = getchar_unlocked ()) < 48);\
    n += (c - '0');\
    \
    while ((c = getchar_unlocked ()) >= 48)\
    n = n * 10 + (c - '0');\
    }\
     
    int main()
    {
    int t,max_leaves,curr_leaves,i,k,f=0;char c;
    read(t);
     
    while(t--)
    {
     
    read(k);
     
    max_leaves=1;
     
     
    while(k--)
    {
    read(curr_leaves);
     
    //if no of leaves are more than can be, exit
    if(curr_leaves>max_leaves)
    {
    f=1;break;
    }
     
    max_leaves=(max_leaves-curr_leaves)<<1;
    }
     
     
    if(f||max_leaves)
    {
    f=0;
    puts("No\n");
    }
     
    else
    puts("Yes\n");
     
     
    }
     
    return 0;
    }
