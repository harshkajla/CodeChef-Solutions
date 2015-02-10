#include<stdio.h>
#include<math.h>
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
int main()
{
	int t,n,tt,Dt,travelT,dt,i,x,l,f;
	tt=read_int();
	while(tt--)
	{
		n=read_int();
		x=read_int();
		l=read_int();
		f=read_int();
		t=x+l;
		for(i=1;i<n;i++)
		{
			x=read_int();
			l=read_int();
			f=read_int();
			t+=(int)((ceil((t-x)/(f+0.0)))*f)+x-t+l;
		}
		printf("%d\n",t);
	}
	return 0;
}
