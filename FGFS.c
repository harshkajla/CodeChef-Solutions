#include<stdio.h>
struct customer{
long int startT;
long int endT;
long int compart;
};
typedef struct customer customer;
void merge(customer* a, long int low, long int mid, long int high,customer* aux, int flag);
int main()
{
	short int t;
	scanf("%hd",&t);
	while(t--)
	{
		long int n,k,customers=0,i,pref;
		scanf("%ld%ld",&n,&k);
		customer endtime;
		customer persons[n],aux[n];
		//initialising endtimes
		endtime.endT = 0;
		endtime.compart=0;
		endtime.startT=0;
		for(i=0;i<n;i++)
		scanf("%ld%ld%ld",&persons[i].startT,&persons[i].endT,&persons[i].compart);
		msort(persons,0,n-1,aux,1);
		msort(persons,0,n-1,aux,2);
		for(i=0;i<n;i++)
		{
			pref = persons[i].compart;
			if(pref!=endtime.compart)
				endtime.endT=0;
			//if the new customer starts after previous one leaves
			if(persons[i].startT>=endtime.endT)
			{
				customers++;
				endtime = persons[i];
			}
			//else if customers starts before the previous one leaves
			else
			{
				//if he leaves before the current one as well
				if(persons[i].endT<=endtime.endT)
				{
					endtime = persons[i];
				}
			}
		}
		printf("%ld\n", customers);
	}
	return 0;
}
//merge function
void merge(customer* a, long int low, long int mid, long int high,customer* aux, int flag)
{
        long int i,j,k;     //aux[] is auxillary array that stores a temporarily.
  //first storing a into aux
        for(i=low;i<high+1;i++)
        aux[i]=a[i];
  //merge-sorting
        j=low;
        k=mid+1;
if(flag==1)
        for(i=low;i<=high;i++)
        {
                if(j>mid) a[i]=aux[k++];
                else if(k>high) a[i]=aux[j++];
                else if(aux[j].startT<=aux[k].startT) a[i]=aux[j++];
                else if(aux[j].startT>aux[k].startT) a[i]=aux[k++];
        }
else
	    for(i=low;i<=high;i++)
        {
                if(j>mid) a[i]=aux[k++];
                else if(k>high) a[i]=aux[j++];
                else if(aux[j].compart<=aux[k].compart) a[i]=aux[j++];
                else if(aux[j].compart>aux[k].compart) a[i]=aux[k++];
        }
}
//actual sort function
void msort(customer* a, long int low, long int high,customer* aux,int flag)
{
        long int mid;
        if(high<=low)
        return;
        mid=(low+high)/2;
        if(flag==1)
        {msort(a,low,mid,aux,1);
        msort(a,mid+1,high,aux,1);
        merge(a,low,mid,high,aux,1);
        }
        else
		{msort(a,low,mid,aux,2);
        msort(a,mid+1,high,aux,2);
        merge(a,low,mid,high,aux,2);
		}
}
