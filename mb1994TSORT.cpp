#include<bits/stdc++.h>
using namespace std;
long long c4[100001],c7[100001],ans[100001],sevens_in[100001],fours_in[100001];
    
map<long long, long long>h;
//preprocessing part..
void preprocess()
{
    ans[0]=0;
    for(int i=0;i<=100000;i++)
    {
        fours_in[i]=fours_in[i/10]+(i%10==4);
        c4[i]=c4[i-1]+fours_in[i];
        
        sevens_in[i]=sevens_in[i/10]+(i%10==7);
        c7[i]+=c7[i-1]+sevens_in[i];
    
        ans[i]=ans[i-1]+h[c4[i]-c7[i]];
        h[c4[i]-c7[i]]++;
    }
}
int main()
{
    int t,n;
    preprocess();
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}
