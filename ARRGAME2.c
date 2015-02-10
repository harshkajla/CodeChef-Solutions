#include<stdio.h>
void merge(long int*, long int, long int, long int,long int*);
void msort(long int*, long int, long int,long int*);
void sort(long int* ,long int,long int* );
int main()
{
	short int t;
	long int n,i,j,temp,diffc;
	//double logchef[100000],logsasha[100000],aux[100000];
	double t1,fina=0,c1,c2,c3,s1,s2,s5;
	scanf("%hd",&t);
	while(t--)
	{
		//number of numbers
		scanf("%ld",&n);
		long int chef[n],sasha[n],aux[n];
        fina=0;i=0;j=0;temp=0;c1=0;c2=0;c3=0;s2=0;s1=0;s5=0;t1=0;diffc=0;
		
		//chef's numbers
		for(i=0;i<n;i++)
		{scanf("%ld",&chef[i]);if(chef[i]==3)c3++;
            else if(chef[i]==2)c2++;
            else if(chef[i]==1)c1++;}
		//sasha's numbers
		for(i=0;i<n;i++)
		{scanf("%ld",&sasha[i]);if(sasha[i]==2)s2++;
            else if(sasha[i]==1)s1++;
            else if(sasha[i]>=5)s5++;}
            
		//sorting
		sort(chef,n,aux);
		sort(sasha,n,aux);
		diffc=n-c2-c1;//nos. 3 or more
		/*printf("diffc=%ld\n",diffc);
		printf("1 count=%ld\n",c1);
		printf("2 count=%ld\n",c2);
		printf("3 count=%ld\n",c3);
        printf("s1=%ld\n",s1);
        printf("s2=%ld\n",s2);
        printf("s5=%ld\n",s5);
*/
		//counting for all chef[i]>=3
		for(i=0;i<n;i++)
        {
            temp=chef[i];
            if(temp>=3)
            {
                while(sasha[j]>temp)
                {//printf("(%ld,%ld)",chef[i],sasha[j]);
                    fina+=diffc;
                    j++;
                    if(j==n)
                        break;
                }
                if(j==n)
                    break;
            }
            else
                break;
                diffc--;
                }
//found the count for all except(3,2) and (all but 1,1) and (2,5 onwards)
           // printf("final=%ld\n",fina);
            fina+=c3*s2;
            //printf("(3,2) pairs=%ld\n",c3*s2);
            //printf("(all but 1, 1) pairs=%ld\n",(n-c1)*s1);
            fina+=(n-c1)*s1;
            //printf("2,5 or more) pairs=%ld\n",c2*s5);
            fina+=c2*s5;
            t1=fina/(double)n;
            printf("%lf\n",t1);
	}
		return 0;
        }
//nominal sort function
void sort(long int* a,long int size,long int* aux)
{
	long int low,high;
	low=0;
	high=size-1;
  //calling actual sort function
	msort(a,low,high,aux);
}
//actual sort function
void msort(long int* a, long int low, long int high,long int* aux)
{
	long int mid;
	if(high<=low)
	return;
	mid=(low+high)/2;
	msort(a,low,mid,aux);
	msort(a,mid+1,high,aux);
	merge(a,low,mid,high,aux);
}
//merge function
void merge(long int* a, long int low, long int mid, long int high,long int *aux)
{
	long int i,j,k;	//aux[] is auxillary array that stores a temporarily.
  //first storing a into aux
	for(i=low;i<high+1;i++)
	aux[i]=a[i];
  //merge-sorting
	j=low;
	k=mid+1;
	for(i=low;i<=high;i++)
	{
		if(j>mid) a[i]=aux[k++];
		else if(k>high) a[i]=aux[j++];
		else if(aux[j]>=aux[k]) a[i]=aux[j++];
		else if(aux[j]<aux[k]) a[i]=aux[k++];
	}
}
