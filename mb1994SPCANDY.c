#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct letnum{
	int count;
	char letter;
};
typedef struct letnum letnum;
void initialise(letnum* a);
int main()
{
	int t,i,j,l1,l2;
	char letters[26];
	letnum counter[26],temp;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		char s1[150001]="",s2[150001]="";
		gets(s1);
		gets(s2);
		l1=strlen(s1);
		l2=strlen(s2);
		initialise(counter);
		for(i=0;i<l2;i++)
		{
			if(!isalpha(s2[i]))
			continue;
			if(isupper(s2[i]))
			counter[s2[i]-'A'].count++;
			else
			counter[s2[i]-'a'].count++;
		}
		//bubblesorting in asc order
		for(i=0;i<25;i++)
		{
			for(j=i+1;j<26;j++)
			{
				if(counter[i].count>counter[j].count)
				{
					temp = counter[i];
					counter[i] = counter[j];
					counter[j] = temp;
				}
				else if(counter[i].count==counter[j].count)
				{
					if(counter[i].letter>counter[j].letter)
					{
						temp = counter[i];
					counter[i] = counter[j];
					counter[j] = temp;
					}
				}
			}
		}
		//storing alphabets from the freq seq
		for(i=25;i>=0;i--)
		{
			if(counter[i].count==0)break;
			letters[counter[i].letter-'a'] = s1[i];
		}
		for(i=0;i<l2;i++)
		{
			if(!isalpha(s2[i]))
			{printf("%c",s2[i]);continue;}
			if(isupper(s2[i]))
			printf("%c",toupper(letters[s2[i]-'A']));
			else
			printf("%c",letters[s2[i]-'a']);
		}
		printf("\n");
	}
	return 0;
}
void initialise(letnum* a)
{
	int i;
	for(i=0;i<26;i++)
	{
		a[i].count=0;
		a[i].letter=i+'a';
	}
}
