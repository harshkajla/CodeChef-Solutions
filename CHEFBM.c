#include<stdio.h>
#define gc getchar_unlocked
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
struct location
{
	int i;
	int j;
};
typedef struct location location;
//merge function
void merge(location* a, int low, int mid, int high,location* aux)
{
	int i,j,k;	//aux[] is auxillary array that stores a temporarily.
  //first storing a into aux
	for(i=low;i<high+1;i++)
	aux[i]=a[i];
  //merge-sorting
	j=low;
	k=mid+1;
	for(i=low;i<=high;i++)
	{
		if(j>mid) a[i]=aux[k++];
		else if(k>high) a[i]=aux[j++];
		else if(aux[j].i<=aux[k].i) a[i]=aux[j++];
		else if(aux[j].i>aux[k].i) a[i]=aux[k++];
	}
}
//actual sort function
void msort(location* a, int low, int high,location* aux)
{
	int mid;
	if(high<=low)
	return;
	mid=(low+high)/2;
	msort(a,low,mid,aux);
	msort(a,mid+1,high,aux);
	merge(a,low,mid,high,aux);
}
void sort(location* a,int size,location* aux)
{
	int low,high;
	low=0;
	high=size-1;
  //calling actual sort function
	msort(a,low,high,aux);
}
int main()
{
	int row,col,p,i,start,ROW,COL,NEXTCOL,index;
	row=read_int();col=read_int();p=read_int();
	location increments[p];
	location aux[p];
	int ans[row+1];
	int values[col+1],visited[col+1];
	for(i=0;i<=col;i++)
	{
		visited[col]=-1;
	}
	for(i=0;i<p;i++)
	{
		increments[i].i=read_int();
		increments[i].j=read_int();
	}
	/*printf("\n");
	for(i=0;i<p;i++)
	{
		printf("%d %d\n",increments[i].i,increments[i].j);
	}*/
	for(i=1;i<=row;i++)
	{
		ans[i]=col-1;
	}
	sort(increments,p,aux);
	//printf("sorted..\n");
/*
	for(i=0;i<p;i++)
	{
		printf("%d %d\n",increments[i].i,increments[i].j);
	}
*/
	for(i=0;i<p;i++)
	{
		//get the first unvisited row..
		start=increments[i].i;
		index=i;
	//	printf("start=%d\n",start);
		while(i<p && increments[i].i==start)
		{
		//	printf("%d %d\n",increments[i].i,increments[i].j);
			ROW=increments[i].i;
			COL=increments[i].j;
			NEXTCOL=COL+1;
			//check if that column and its next are visited by that row or not..
			if(visited[COL]!=ROW)
			{
				visited[COL]=ROW;
				values[COL]=COL;
			}
			if(COL!=col && visited[NEXTCOL]!=ROW)
			{
				visited[NEXTCOL]=ROW;
				values[NEXTCOL]=NEXTCOL;
			}
			//simply update it now..will check later..
			values[COL]++;
			i++;
		}
		//now check if the updates have been valid..for this row
		i=index;
		//printf("checking..\n");
		while(i<p && increments[i].i==start)
		{
			//printf("%d %d\n",increments[i].i,increments[i].j);
			ROW=increments[i].i;
			COL=increments[i].j;
			NEXTCOL=COL+1;
			if(COL==col && col!=1)
			{
				ans[ROW]++;
			}
			else
			{
				if(col!=1 && values[COL]>values[NEXTCOL])
				{/*printf("problem here..\n");*/ans[ROW]=-1;while(increments[i].i==start)i++;break;}
				if(COL==1 && col!=1)ans[ROW]--;
			}
			i++;
		}
		i--;
	}
	for(i=1;i<=row;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
