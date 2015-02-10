#include<stdio.h>
#include<string.h>
int main()
{
    int i=0;
    char str[101];
    gets(str);
    while(str[i]!='\0')
    {
        printf("%c",str[i]-7);
        i++;
    }
    return 0;
}
