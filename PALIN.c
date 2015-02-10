#include<stdio.h>
//399 gives 499
//3989-4004 instead of 3993
#define next(a) a<'9'?(a+1):'0'
char str[1000001];
int main()
{
	int t,just9,i,mid1,mid2,tmid1,tmid2,l,palin,mirror;
	char c;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		i=0;just9=1;
		while((c=getchar())!='\n')
		{
			str[i++]=c;
			if(c!='9')just9=0;
		}
		str[i]='\0';
		l=i;
		//all 9s
		if(just9==1)
		{
			printf("1");
			for(i=2;i<=l;i++)
				printf("0");
			printf("1\n");
			continue;
		}
		//calculating mid
		if(l&1)//odd: 1 center
		{
			mid1=mid2=l/2;//0-based mid
		}
		else
		{
			mid2=l/2;
			mid1=mid2-1;
		}
	//printf("mid1=%d mid2=%d\n",mid1,mid2);
	//printf("len=%d\n",l);
		//traversing from middle:
		palin=1;
		mirror=0;//is 1 if directly putting left to right is possible
		tmid1=mid1;tmid2=mid2;
		while(tmid1>=0 && tmid2<l)
		{
			//printf("%c %c\n",str[tmid1],str[tmid2]);
			if(str[tmid1]!=str[tmid2])
			{
				palin=0;
				if(str[tmid2]>str[tmid1])
				{
					if(mirror==1)str[tmid2]=str[tmid1];
					else
					break;
				}
				else
				{
					mirror=1;
					str[tmid2]=str[tmid1];
				}
			}
			tmid1--;tmid2++;
		}
		tmid1=mid1;tmid2=mid2;
		if(palin==1)
		{
			//printf("palindrome");
			//updating mid digit:
			str[tmid1]=str[tmid2]=next(str[tmid1]);
			//propagating the carry
				if(str[tmid1]=='0')
				{
					tmid1--;
					while(str[tmid1]=='9')
					{
						str[tmid1]='0';
						str[l-1-tmid1]='0';
						tmid1--;
					}
					str[tmid1]++;
					str[l-1-tmid1]=str[tmid1];
				}
			//reflecting it from left to right
			while(tmid1>=0)
			{
				str[l-1-tmid1]=str[tmid1];
				tmid1--;
			}
		}
		//not palindrome:
		else if(mirror==0)
		{
			//printf("mirror not possible\n");
			tmid1=mid1;tmid2=mid2;
			str[tmid1]=str[tmid2]=next(str[tmid1]);
			//printf("%c %c\n",str[tmid1],str[tmid2]);
			//propagating the carry
				if(str[tmid1]=='0')
				{
					tmid1--;
					while(str[tmid1]=='9')
					{
						str[tmid1]='0';
						str[l-1-tmid1]='0';
						tmid1--;
					}
					str[tmid1]++;
					str[l-1-tmid1]=str[tmid1];
				}
			//reflecting it from left to right
			while(tmid1>=0)
			{
				str[l-1-tmid1]=str[tmid1];
				tmid1--;
			}
		}
		printf("%s\n",str);
	}
	return 0;
}
