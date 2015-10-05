#include <bits/stdc++.h>
#define mod 1000000007
#define rep(i,n) for(int i=0; i<n; i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define mp make_pair
#define pb push_back
#define gtc getchar()
#define black 1
#define white 0
#define red 2
 
typedef long long ll;
using namespace std;
int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
}
 
int n,m;
int xc[10001],xc1[10001],xc2[10001],xc3[10001];
int yc[10001],yc1[10001],yc2[10001],yc3[10001];
int dir[10001],dir1[10001];
int mat[111][111],mat1[111][111];
 
int findud(int, int);
int findlr(int, int);
 
pair<int, int> random_white(int r, int c)
{
	int x,y,i=0,xx,yy,tmp,maxi=-1;
	
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		if(mat[i][j]==white)return mp(i,j);
	}
	
}
pair<int, int> random_white1(int r, int c)
{
	int x,y,i=0,xx,yy,tmp,maxi=-1;
	
	while(true)
	{
		x=r-rand()%r;
		y=c-rand()%c;
		if(mat[x][y]==white)return mp(x,y);
	}
}
  
int findud(int x, int y)
{
	int tmp=x-1,ans=0;
	
	while(tmp>0 && mat[tmp--][y]==white)
	ans++;
	
	while(x<=n && mat[x++][y]==white)
	ans++;
	
	return ans;
}
 
int findlr(int x, int y)
{
	int tmp,ans=0;
	
	tmp=y-1;
	
	while(tmp>0 && mat[x][tmp--]==white)
	ans++;
	
	while(y<=m && mat[x][y++]==white)
	ans++;
	
	return ans;
}
 
void paint(int x, int y, int direction)
{
	//puts("in pnt");
	int tmp;
	if(direction==1)
	{
		//updown..
		tmp=x-1;
		
		while(tmp>0 && mat[tmp][y]==white)
		mat[tmp--][y]=red;
		
		while(x<=n && mat[x][y]==white)
		mat[x++][y]=red;
	}
	
	else
	{
		//left right..
		tmp=y-1;
		
		while(tmp>0 && mat[x][tmp]==white)
		mat[x][tmp--]=red;
		
		while(y<=m && mat[x][y]==white)
		mat[x][y++]=red;
	}
}
 
int main()
{
	int k,occupied,required,i,j,nstep,ud,lr,nstep1,nstep2,nstep3,f=0;
	
	pair<int, int> cell;
	
	s(n);s(m);s(k);
	
	occupied=k;required=n*m;
	rep(x,k)
	{
		s(i);s(j);
		mat[i][j]=black;
		mat1[i][j]=black;
	}
	
	//printf("done");
	/////////////////////method 1: best direction//////////////////////////////////////
	nstep=0;
	while(occupied!=required)
	{
		//choosing a random white cell..
		cell=random_white(n,m);
		
		//printf("random cell=[%d,%d]\n",cell.first,cell.second);
		xc[nstep]=cell.first;
		yc[nstep]=cell.second;
			
		//choosing to go either updown or leftright..
		ud=findud(cell.first,cell.second);
		lr=findlr(cell.first,cell.second);
		
		//printf("ud=%d lr=%d\n",ud,lr);
		if(ud>=lr)
		{
			//choose to go up..			
			dir[nstep++]=1;
			
			paint(cell.first,cell.second, 1);
			occupied+=ud;
		}
		
		else
		{
			//choose to go lr..
			dir[nstep++]=0;
			
			paint(cell.first,cell.second,0);
			occupied+=lr;
		}
		
	}
	
	//printf("method 1 done");
	////////////////////////////////////////////////////////////////////////
	
	/////method 2: only horizontal/////////////////////////////////////////////
	
	occupied=k;nstep1=0;
	
	//reinitializing.
	rep(i,n)
	{
		rep(j,m)
		{
			mat[i+1][j+1]=mat1[i+1][j+1];
		}
	}
	
	while(occupied!=required)
	{
		//choosing a random white cell..
		cell=random_white(n,m);
		
		//printf("random cell=[%d,%d]\n",cell.first,cell.second);
		xc1[nstep1]=cell.first;
		yc1[nstep1++]=cell.second;
		lr=findlr(cell.first,cell.second);
		//printf("lr=%d\n",lr);
		paint(cell.first,cell.second,0);
		occupied+=lr;
	}
	
	//printf("method 2 done");
	///////////////////////method 3: only vertical/////////////////////////
	
	occupied=k;nstep2=0;
	
	//reinitializing.
	rep(i,n)
	{
		rep(j,m)
		{
			mat[i+1][j+1]=mat1[i+1][j+1];
		}
	}
	
	while(occupied!=required)
	{
		//choosing a random white cell..
		cell=random_white(n,m);
		
		//printf("random cell=[%d,%d]\n",cell.first,cell.second);
		xc2[nstep2]=cell.first;
		yc2[nstep2++]=cell.second;
 
		ud=findud(cell.first,cell.second);
		
		paint(cell.first,cell.second, 1);
		occupied+=ud;
	}
	//printf("method 3 done");
	
	////////method 4: alternate between lr and ud..../////////////////later try this with random cells..
	nstep3=0;occupied=k;f=0;
	//reinitializing.
	rep(i,n)
	{
		rep(j,m)
		{
			mat[i+1][j+1]=mat1[i+1][j+1];
		}
	}
	
	while(occupied!=required)
	{
		//choosing a random white cell..
		cell=random_white1(n,m);
		
		//printf("random cell=[%d,%d]\n",cell.first,cell.second);
		xc3[nstep3]=cell.first;
		yc3[nstep3]=cell.second;
			
		//choosing to go either updown or leftright..
		if(f==0)
		{
			lr=findlr(cell.first,cell.second);
			
			//choose to go lr..
			dir1[nstep3++]=0;
			
			paint(cell.first,cell.second,0);
			occupied+=lr;
		}
		
		
		else
		{
			ud=findud(cell.first,cell.second);
		
			//choose to go up..			
			dir1[nstep3++]=1;
			
			paint(cell.first,cell.second, 1);
			occupied+=ud;
		}
		f=1-f;
	}
	
	int m=min(min(nstep,nstep3),min(nstep1,nstep2));
	
	if(m==nstep)
	{
		p(nstep);
		rep(i,nstep)
		{
			printf("%d %d %d\n",xc[i],yc[i],dir[i]);
		}
	}
	
	else if(m==nstep1)
	{
		p(nstep1);
		rep(i,nstep1)
		{
			printf("%d %d %d\n",xc1[i],yc1[i],0);
		}
	}
	
	else if(m==nstep2)
	{
		p(nstep2);
		rep(i,nstep2)
		{
			printf("%d %d %d\n",xc2[i],yc2[i],1);
		}
	}
	
	else
	{
		p(nstep3);
		f=0;
		rep(i,nstep3)
		{
			printf("%d %d %d\n",xc3[i],yc3[i],f);
			f=1-f;
		}
	}
	
	
	return 0;
}
