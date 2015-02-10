#include<stdio.h>
#define gc getchar_unlocked
int open[1001];
char call[20];
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
int main()
{
	int n,k,twt,i,ans,j;
	ans=0;
	n=read_int();
	k=read_int();
	///getchar();
		for(i=0;i<k;i++)
		{
			gets(call);
			//printf("i=%d call=%s\n",i,call);
			if(call[4]=='K')
			{
				twt=0;
				for(j=6;call[j]!='\0';j++)
				{
					twt=twt*10+(call[j]-'0');
				}
				//printf("Twt=%d\n",twt);
				if(open[twt])//open then close
				{
					//printf("was open..now closed..\n");
					ans--;open[twt]=0;
					printf("%d\n",ans);
				}
				else//close then open
				{
					//printf("was closed..now open\n");
					open[twt]=1;ans++;printf("%d\n",ans);
				}
			}
			else
			{
				for(j=0;j<1001;j++)open[j]=0;printf("0\n");ans=0;
			}
		}
		return 0;
}
