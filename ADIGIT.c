#include<stdio.h>
#include<math.h>
#define gc getchar_unlocked
int freq[100001][10];
inline int read_int() {
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
	int n,m,i,j,sum,index;
	char c;
	n=read_int();m=read_int();
	char a[n+1];i=1;
	scanf("%s",a+1);
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			for(j=0;j<10;j++)
				freq[i][j]=0;
		}
		else
		{
			for(j=0;j<10;j++)
				freq[i][j]=freq[i-1][j];
		}
		freq[i][a[i]-'0']++;
	}
	for(i=0;i<m;i++)
	{
		index=read_int();
		sum=0;
		for(j=0;j<10;j++)
		{
			sum+=abs(a[index]-'0'-j)*freq[index][j];
		}
		printf("%d\n",sum);
	}
	return 0;
}
