#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<iostream>
#include<set>
#include<stack>
#include<string>
#include<cstdlib>
#include<sstream>
using namespace std;
int main()
{
    int t,r,c,i,j,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&r,&c);
        getchar();
        char str[r][c];
        for(i=0;i<r;i++)
        {
            scanf("%s",str[i]);
            getchar();
        }
        f=0;c-=4;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if((str[i][j]=='S'||str[i][j]=='s')&&(str[i][j+1]=='P'||str[i][j+1]=='p')&&(str[i][j+2]=='O'||str[i][j+2]=='o')&&(str[i][j+3]=='O'||str[i][j+3]=='o')&&(str[i][j+4]=='N'||str[i][j+4]=='n'))
                {f=1;break;}
            }
            if(f)break;
        }
        if(f)
        {
            puts("There is a spoon!");
            continue;
        }
        c+=4;r-=4;
        for(i=0;i<c;i++)
        {
            for(j=0;j<r;j++)
            {
                if((str[j][i]=='S'||str[j][i]=='s')&&(str[j+1][i]=='P'||str[j+1][i]=='p')&&(str[j+2][i]=='O'||str[j+2][i]=='o')&&(str[j+3][i]=='O'||str[j+3][i]=='o')&&(str[j+4][i]=='N'||str[j+4][i]=='n'))
                {f=1;break;}
            }
        }
        if(f)
        {
            puts("There is a spoon!");
        }
        else
        puts("There is indeed no spoon!");
    }
	return 0;
}
