#include<stdio.h>
#include<utility>
#include<algorithm>
#define gc getchar_unlocked
using namespace std;
int marked[1001];
int mpairs[10001];
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
	int t,n,m,i;
	pair<int, int> pairs[10001];
	t=read_int();
	while(t--)
	{
		for(i=0;i<1001;i++)marked[i]=0;
		for(i=0;i<10001;i++)mpairs[i]=0;
		n=read_int();m=read_int();
		for(i=0;i<m;i++)
		{
			pairs[i].first=read_int();
			pairs[i].second=read_int();
		}
		for(i=m-1;i>=0;i--)
		{
			if(!marked[pairs[i].first] && !marked[pairs[i].second])
			{
				marked[pairs[i].first]=marked[pairs[i].second]=1;
				mpairs[i]=1;
			}
		}
		for(i=0;i<m;i++)
		{
			if(mpairs[i]==1)
				printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
