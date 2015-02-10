#include<stdio.h>
#include<string.h>
int main()
{int test,index,i;
char input[315];
char output[315];
int hash[26];
scanf("%d",&test);
getchar();
while(test--)
{for(i=0;i<26;i++)
hash[i]=0;
memset(output,0,315);
index=0;
char c;
gets(input);
for(i=0;i<strlen(input);i++)
{if(input[i]>=65&&input[i]<=90)
hash[input[i]-65]++;
else if(input[i]>=97&&input[i]<=122)
hash[input[i]-97]++;
}
for(i=0;i<26;i++)
if(hash[i]==0)
{output[index++]=i+97;
}
	if(strlen(output)==0)
	printf("~\n");
	else
	printf("%s\n",output);
}
}
