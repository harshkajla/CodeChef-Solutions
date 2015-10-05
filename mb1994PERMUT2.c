#include<stdio.h>
int main()
{
 	int n,i=1,pos1,pos2;
	int x1,x2,x3,y1,y2,y3;
	 double area,ma,mi;
 	scanf("%d",&n);
 	while(n--)
 	{
	 		  scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	 		  area = x1*(y2-y3);
	 		  area += x2*(y3-y1);
	 		  area += x3*(y1-y2);
	 		  area /= 2;
	 		  if(area<0)
                    area = -area;
	 		  if (i==1)
              {
                  pos1=1;
                  pos2=1;
                  ma=area;
                  mi=area;
              }
	 		  if(area>=ma)
	 		  {ma=area;pos1=i;}
	 		  if(area<=mi)
	 		  {mi=area;pos2=i;}
			  i++;
    }
			  printf("%d %d\n",pos2,pos1);
			  return 0;
}
