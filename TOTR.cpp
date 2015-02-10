#include<stdio.h>
#include<string.h>
#include<ctype.h>
char str[20000];
int main()
{
	int t,l,i;
	char alphabet[27];
	scanf("%d",&t);
	scanf("%s",alphabet);
	while(t--)
	{
		scanf("%s",str);
		l=strlen(str);
		for(i=0;i<l;i++)
		{
			if(str[i]=='_')
				putchar(' ');
			else if(!isalpha(str[i]))
				putchar(str[i]);
			else
			{
				if(isupper(str[i]))
				{
					putchar(toupper(alphabet[tolower(str[i])-97]));
				}
				else putchar(alphabet[str[i]-97]);
			}
		}
		putchar('\n');
	}
	return 0;
}
