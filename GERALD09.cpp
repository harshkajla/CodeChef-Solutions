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
    char c[4]={'G','C','A','T'};
    int t,n,m,k,i,j,ran,tt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=n;i++)
        {
            tt=i;
            for(j=1;j<=m;j++)
            {
                int x=(i*j+j)%4;
                switch(x)
                {
                    case 0:
                    putchar('G');
                    break;
                    case 1:
                    putchar('T');
                    break;
                    case 2:
                    putchar('A');
                    break;
                    case 3:
                    putchar('C');
                }
            }
            putchar('\n');
        }
    }
	return 0;
}
