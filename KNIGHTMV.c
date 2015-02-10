#include<stdio.h>
#include<ctype.h>
int main()
{
	int t,l,i,x,y;
	char str[11];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		for(i=0;i<11;i++)str[i]='\0';
		gets(str);
		//checking characters
		l=strlen(str);
		if(l!=5)
		{printf("Error\n");continue;}
		if(!((str[0]>='a' && str[0]<='h') && (str[1]>='1' && str[1]<='8') && (str[2]=='-') && (str[3]>='a' && str[3]<='h') && (str[4]>='1' && str[4]<='8')))
		{
			printf("Error\n");
			continue;
		}
		x=str[0]-str[3];if(x<0)x=-x;
		y=str[1]-str[4];if(y<0)y=-y;
		if((x*x+y*y)==5)
		{
			printf("Yes\n");
		}
		else
			printf("No\n");
	}
	return 0;
}
