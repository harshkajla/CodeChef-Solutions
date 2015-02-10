#include<stdio.h>
#include<algorithm>
#include<math.h>
#define gc getchar_unlocked
struct xvalue
{
	int marked;
	int ymax;
	int ymin;
};
typedef struct xvalue xvalue;
xvalue xs[10001];
using namespace std;
int read_int() {
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
	int t,n,x,prevx,prevy,minx,i,y,dx,dy;
	double dist;
	t=read_int();
	while(t--)
	{
		n=read_int();
		minx=10001;
		for(i=0;i<n;i++)
		{
			x=read_int();
			y=read_int();
			if(xs[x].marked!=(t+1))
			{
				xs[x].marked=t+1;
				xs[x].ymax=xs[x].ymin=y;
			}
			if(y>xs[x].ymax)xs[x].ymax=y;
			else if(y<xs[x].ymin)xs[x].ymin=y;
			minx=min(minx,x);
		}
		prevx=minx;prevy=xs[prevx].ymax;
		dist=0;
		for(i=minx;i<10001;i++)
		{
			if(xs[i].marked==(t+1))
			{
				dx=i-prevx;
				dy=xs[i].ymax-prevy;
				prevx=i;
				prevy=xs[i].ymin;
				dx*=dx;
				dy*=dy;
				dist+=xs[i].ymax-xs[i].ymin;
				dist+=sqrt(dx+dy);
			}
		}
		printf("%.2lf\n",dist);
	}
	return 0;
}
