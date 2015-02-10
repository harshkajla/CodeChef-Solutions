#include<stdio.h>
#include<iostream>
using namespace std;
int mini[40];
int maxi[40];
int main()
{
    int t,n,m;
    int i;
	maxi[0]=mini[0]=0;
	
	for(i=1;i<32;i++)
	{
		maxi[i]=maxi[i-1]+ i+1;
		mini[i]=mini[i/2]+ mini[i-i/2 -1] + i+1;
	}
    
    cin>>t;
    
    while(t--)
    {
        cin>>n>>m;
        
        int wirelen=mini[n];
        int maxlen=maxi[n];
        
       // printf("%d\n",wirelen);
        if(wirelen>m)
        puts("-1");
        
        else
        {
            if(m<=maxlen)
            puts("0");
            
            else cout<<m-maxlen<<endl;
        }
    }
    
    return 0;
}
