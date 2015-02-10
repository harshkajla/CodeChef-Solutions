#include<stdio.h>
#include<string.h>
char map[150];
char str[1000001];
int main()
{
    int t,ll,rr,l,i,n,dot,zero;
    char c,p;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<150;i++)map[i]=i;
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            c=getchar();
            getchar();
            p=getchar();
            getchar();
            map[c]=p;
        }
        gets(str);
        //printf("string=%s\n",str);
        l=strlen(str);
        dot=-1;
        for(i=0;i<l;i++)
        {
            str[i]=map[str[i]];
            if(str[i]=='.')dot=i;
        }
        //if dot doesnt exist
        if(dot==-1)
        {
            ll=0;zero=1;
            for(i=0;i<l;i++)
            {
                if(str[i]!='0')zero=0;
                if(!zero)putchar(str[i]);
            }
            if(zero)putchar('0');
            putchar('\n');
        }
        //else dot exists..
        else
        {
            ll=0;rr=l-1;
            for(i=0;i<=dot;i++)
            {
                if(str[i]!='0'){ll=i;break;}
            }
            for(i=l-1;i>=dot;i--)
            {
                if(str[i]!='0'){rr=i;break;}
            }
            if(ll==rr)
            {
                printf("0\n");
            }
            else if(str[ll]=='.')
            {
                for(i=ll;i<=rr;i++)
                putchar(str[i]);
                putchar('\n');
            }
            else if(str[rr]=='.')
            {
                for(i=ll;i<=rr-1;i++)putchar(str[i]);
                putchar('\n');
            }
            else
            {
                for(i=ll;i<=rr;i++)putchar(str[i]);
                putchar('\n');
            }
        }
    }
    return 0;
}
