#include<bits/stdc++.h>
#define lol long long
using namespace std;
lol a[100001];
//taken from geeksforgeeks.
//url:http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
lol maxSubArraySum(int size)
{
   lol max_so_far = 0, max_ending_here = 0;
   int i;
   for(i = 0; i < size; i++)
   {
     max_ending_here = max_ending_here + a[i];
     if(max_ending_here < 0)
        max_ending_here = 0;
     if(max_so_far < max_ending_here)
        max_so_far = max_ending_here;
    }
    return max_so_far;
}
int main()
{
    int t,n;
    lol x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&x);
        
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]-=x;
        }
        
        printf("%lld\n",maxSubArraySum(n));
    }
    
}
