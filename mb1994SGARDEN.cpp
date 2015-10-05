#include<bits/stdc++.h>
using namespace std;
int copied[100], arr[100], temp[100],l[100],r[100],perm[100];
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
int merge(int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (copied[i] <= copied[j])
    {
      temp[k++] = copied[i++];
    }
    else
    {
      temp[k++] = copied[j++];
  
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }
  
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = copied[i++];
  
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = copied[j++];
  
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    copied[i] = temp[i];
  
  return inv_count;
}
int _mergeSort(int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
  
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(left, mid);
    inv_count += _mergeSort(mid+1, right);
  
    /*Merge the two parts*/
    inv_count += merge(left, mid+1, right);
  }
  return inv_count;
}
  
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            perm[i]=i+1;
        }
        
        //permute thru all permutations..
        int o=0,e=0;
        while(1)
        {
            //first check if this permutation contains the given property of columns being black..
            int f=0;
            for(int i=0;i<n;i++)
            {
                //coordinates are (i,perm[i]-1)
                //check if perm[i]-1 >= l[i] && perm[i]-1<=r[i]
                if(perm[i] >= l[i] && perm[i]<=r[i]);
                else
                {
                    f=1;break;
                }
            }
            
            if(f==1)
            {
                if(!next_permutation(perm,perm+n))
                    break;
                else continue;
            }
            
            //find no of inversions in this permutation..
            copy(perm,perm+n,copied);
            int x=_mergeSort(0,n-1);
            if(x&1)o++;
            else e++;
            
            if(!next_permutation(perm,perm+n))
                break;
        }
        
        if(o==e)
            puts("Draw");
        else if(o>e)
            puts("Fedor");
        else puts("Alex");
    }
    return 0;
}
