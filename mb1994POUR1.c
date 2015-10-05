#include<stdio.h>
#define gc getchar_unlocked
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
int cuts[50000001];
int main()
{
	int t,n,k,p,x,i,f,y;
	t=read_int();
	while(t--)
	{
		n=read_int();
		k=read_int();
		p=read_int();
		for(i=0;i<k;i++)
		{
			x=read_int();
			y=read_int();
			cuts[x]=t+1;
			cuts[(y+1)%n]=t+1;
		}
		f=0;
		for(i=0;i<p;i++)
		{
			x=read_int();y=read_int();
			if(cuts[x]!=(t+1) || cuts[(y+1)%n]!=(t+1))f=1;
		}
		if(f==1)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
