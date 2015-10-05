#include<stdio.h>
char letters[10]={' ',' ','A','D','G','J','M','P','T','W'};
int main()
{
        int t;char str[100];
        scanf("%d",&t);
        while(t--)
        {
            scanf("%s",str);
            convert(str,0);
            printf("\n");
        }
        return 0;
}
void convert(char* str, int i)
{int count=0;char ch;
    if(str[i]=='\0')return;
    if(str[i]=='#'){convert(str,i+1);return;}
    ch=str[i];i+=1;
    while(str[i]==ch)
    {count++;i++;}
    printf("%c",letters[ch-48]+count);
    convert(str,i);
}
