#include<stdio.h>
#include<stdbool.h>
int main()
{
	int t,x,y;
	bool ans;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d",&x,&y);
		
		ans=false;
		
		ans=ans||(y%2==0 && (y<=0 && (x>=y && x<=((-y)+1)) || (y>0 && (x>=(-y) && x<=(y-1))) )) || (x>0 && x%2==1 && (y>=(-x+1) && y<=(x+1))) || (x<0 && (-x)%2==0 && y>=x && y<=(-x)); 
		if(ans)
		puts("YES");
		else puts("NO");
	}
	
	return 0;
	
}
