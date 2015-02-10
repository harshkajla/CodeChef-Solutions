#include<bits/stdc++.h>
using namespace std;
string bogie[100];
int ans[7];
int ncr(int n, int r)
{
    if(r==0 || n==r)
        return 1;
    
    else return ncr(n-1,r) + ncr(n-1,r-1);
}
int main()
{
    int x,n,val;
    val=0;
    scanf("%d %d",&x,&n);
    for(int i=0;i<n;i++)
        cin>>bogie[i];
    //finding number of compartments with 1..6 vacant spaces.
    
    //for each bogie..
    for(int i=0;i<n;i++)
    {
	int vacant;
        //for each compartment..
        for(int j=1;j<=9;j++)
        {
            vacant = 0;
            int start=4*j-3;
	 
            for(;start<=4*j;start++)
            {
                vacant += bogie[i][start-1]=='0';
            }
            //now for the other two seats.
            vacant += bogie[i][55-2*j]=='0';
            vacant += bogie[i][54-2*j]=='0';
            if(vacant >= x)
                val += ncr(vacant,x);
        }
    }
    cout<<val<<endl;
    return 0;
}
