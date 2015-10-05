#include<stdio.h>
int hash[20001];
int conflict[21][21];
int final[20];
#define gc() getchar_unlocked()
#define read_int(n) n=0; c=gc();while(c<'0' || c>'9')c=gc();while(c>='0' && c<='9'){n= (n<<3)+(n<<1)+c-48;c=gc();}
void init(int* hash)
{
	int i;
	for(i=0;i<20001;i++)
	hash[i]=0;
}
int main()
{
	int num_stamps,num_offers,i,j,k,l,f, max_c, combinations, current_offer_index, temp_i, c;
	init(hash);
	for(i=0;i<21;i++)
	for(j=0;j<21;j++)
	conflict[i][j]=0;
	//n stamps, m offers
	read_int(num_stamps);
	read_int(num_offers);
	int offers[num_offers+1][20001];
	int num_stamps_in_offer[num_offers+1];
	//for all m offers, accept (k, a1,a2,a3,..)
	for(i=1;i<=num_offers;i++)
	{
		//printf("offer %d..\n",i);
		read_int(num_stamps_in_offer[i]);	//k stamps in offer[i]
		for(j=1;j<=num_stamps_in_offer[i];j++)
		{
			read_int(offers[i][j]);
		}
		//printf("Accepted.\n");
	}
	//accepting done
	//first i can mark the offers which have a conflict between them, so they can never be chosen together.
	//there are at most 20 offers.
	//for each offer:
	for(i=1;i<=num_offers;i++)
	{
		f=0;
//		printf("Offer %d\n",i);
		init(hash);
		//mark all stamps that are in offer[i]
		for(j=1;j<=num_stamps_in_offer[i];j++)
		{
//			printf("%d ",offers[i][j]);
			hash[offers[i][j]]=1;
		}
//		printf("\n");
		//for all remaining offers from i:
		for(k=i+1;k<=num_offers;k++)
		{
			f=0;
//			printf("comparing with offer %d..\n",k);
			for(l=1;l<=num_stamps_in_offer[k];l++)
			{
				//if it was already marked:
				if(hash[offers[k][l]])
				{
					//declare a conflict and break
					conflict[i][k]=conflict[k][i]=1;
//					printf("Conflict between %d and %d \n",k, i);
					f=1;
					break;
				}
			}
			if(f==0)
			conflict[i][k]=conflict[k][i]=0;
		}
	}
//	printf("\n\nconflicts found.\n\n");
	//conflicts declared.
	combinations = (1<<num_offers) -1;	//total number of ways in which i can choose the offers
	current_offer_index=0;
	max_c=0;
//	printf("combinations = %d\n",combinations);
	for(i=0;i<=combinations;i++)
	{
		temp_i=i;c=0;current_offer_index=1;f=0;
		for(j=0;j<=20;j++)
		final[j]=0;
//		printf("i = %d\n",i);
		//for all the bits of i
		while(temp_i)
		{
	
			//if the current bit of i is 1, choose the subset with index=bit number of i
			if(temp_i&1)
			{
//				printf("1bit position = %d\n",current_offer_index);
				//checking if this offer has any conflict with other accepted offers.
				for(j=0;j<c;j++)
				{
					//if conflict found, no need to proceed further:
					if(conflict[current_offer_index][final[j]] == 1)
					{
//						printf("conflict found between %d and %d\n",current_offer_index, final[j]);
						f=1;break;
					}
				}
	
				//if no conflicts found, insert that index to final offers.
				if(f==0)
				{
					final[c++]=current_offer_index;
				}
	
				//if conflict found, no use using this i.
				else
				{
					break;
				}
			}
	
			current_offer_index++;
			temp_i=temp_i>>1;
		}
//		printf("count=%d\n",c);
		if(c>max_c)
		{
			max_c=c;
		}
	}
		
	printf("%d\n",max_c);
	return 0;
}
