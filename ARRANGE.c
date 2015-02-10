#include<stdio.h>
int main()
{
	int t,i,val,temp,newindex,bitno,x,k;
	char str[65536],tc;
	int pow2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);//length of bits
		scanf("%s",str);//length of string =2^k-->indices=0 to 2^k -1.
		//mapping from 0 to 2^(k-1)
		val=pow2[k]-1;
		for(i=0;i<=val;i++)
		{
			bitno=k-1;newindex=0;
			temp=i;
			while(bitno>=0)
			{
				x=temp&1;
				temp>>=1;
				if(x)
				{
					newindex+=pow2[bitno];
				}
				bitno--;
			}
			//printf("i=%d-->mapping=%d\n",i,newindex);
			if(newindex>i){
			tc=str[i];
			str[i]=str[newindex];
			str[newindex]=tc;
			}
		}
		printf("%s\n",str);
	}
	return 0;
}
