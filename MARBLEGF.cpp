#include <iostream>
 
#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
 
 
long long int arr[1000000];
long long int sum1[10000]={0},sum2[1000]={0},sum3[100]={0},sum4[10]={0};
 
long long int read_int() {
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
    long long int i,n,q;
    char choice;
 
    n=read_int();
    q=read_int();
 
    for(i=0;i<n;i++)
    {
        arr[i]=read_int();
        sum1[i/100]+=arr[i];
        sum2[i/1000]+=arr[i];
        sum3[i/10000]+=arr[i];
        sum4[i/100000]+=arr[i];
    }
     long long int s;
     long long int t_sum;
    for(s=0;s<q;s++)
    {
      long long int p,r;
 
       std::cin>>choice>>p>>r;
 
      if(choice=='G')
      {
          arr[p]=arr[p]+r;
          sum1[p/100]+=r;
          sum2[p/1000]+=r;
          sum3[p/10000]+=r;
          sum4[p/100000]+=r;
      }
 
      else if(choice=='T')
      {
          arr[p]=arr[p]-r;
          sum1[p/100]-=r;
          sum2[p/1000]-=r;
          sum3[p/10000]-=r;
          sum4[p/100000]-=r;
      }
 
        else if(choice=='S')
        {
            long long int j,temp[10];
            t_sum=0;
            j=r-p;
 
            temp[0]=p/100;
            temp[1]=r/100;
            temp[2]=p/1000;
            temp[3]=r/1000;
            temp[4]=p/10000;
            temp[5]=r/10000;
            temp[6]=p/100000;
            temp[7]=r/100000;
 
            if(j<100)
            {
               for(i=p;i<=r;i++)
                    t_sum+=arr[i];
            }
 
            else
            {
                for(i=p;i<(temp[0]+1)*100;i++)
                    t_sum+=arr[i];
 
                for(i=temp[0]+1;(i%10!=0)&&(i<temp[1]) ;i++)
                    t_sum+=sum1[i];
 
                for(i=temp[2]+1;(i%10!=0)&&(i<temp[3]);i++)
                    t_sum+=sum2[i];
 
                for(i=temp[4]+1;(i%10!=0)&&(i<temp[5]);i++)
                    t_sum+=sum3[i];
 
                for(i=temp[6]+1;(i%10!=0)&&(i<temp[7]);i++)
                    t_sum+=sum4[i];
 
 
                for(i=temp[7]*10;i<temp[5] && i!=0;i++)
                    t_sum+=sum3[i];
 
 
 
                for(i=temp[5]*10;i<temp[3] && i!=0;i++)
                    t_sum+=sum2[i];
 
 
 
                for(i=temp[3]*10;i<temp[1] && i!=0;i++)
                    t_sum+=sum1[i];
 
 
 
                for(i=temp[1]*100;i<=r;i++)
                    t_sum+=arr[i];
            }
            printf("%lld\n",t_sum);
            }
        }
return 0;
}
