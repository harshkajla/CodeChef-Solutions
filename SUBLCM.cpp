#include<bits/stdc++.h>
#define pb push_back
#define gc getchar_unlocked
using namespace std;
inline int read_int() {
  register char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
vector<int> factors[1000001];
bool marked[1000001];
int primed[1000001];
int a[1000001];
void sieve()
{
    for(int i=2;i<1000;i++)
    {
        if(marked[i]==false)
        {
            factors[i].pb(i);
            for(int j=i<<1;j<=1000000;j+=i)
            {
                marked[j]=true;
                factors[j].pb(i);
            }
        }
    }
    for(int i=1001;i<=1000000;i+=2)
        if(marked[i]==false)factors[i].pb(i);
}
int main()
{
    int t,n;
    sieve();
    t=read_int();
    while(t--)
    {
        n=read_int();
        memset(primed,0,sizeof primed);
        int templen=0, maxlen=0, prev;
        for(int i=0;i<n;i++)
        {
            a[i]=read_int();
        }
        templen=0;prev=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<factors[a[i]].size();j++)
            {
                int pf=factors[a[i]][j];
                if(primed[pf])
                {
                    //this number conflicts with the continuous previous set of numbers..
                    //so previous sequence stops here..and i need to remove that number with which the factors are
                    //matching..
                    //primed[i]=index of the last number attended whose pf is i
                    maxlen=max(maxlen,templen);
                    int index=primed[pf]-1,number=a[index];
       //             printf("%d is present already..by %d..\n",pf,number);
                    for(int k=0;k<factors[number].size();k++)
                    {
                        primed[factors[number][k]]=0;
                    }
                    primed[pf]=i+1;
                    prev=max(prev,index+1);
                    templen=i-prev;
                }
                else
                primed[pf]=i+1;
            }
            templen++;
            maxlen=max(maxlen,templen);
        }
        printf("%d\n",maxlen<=1?-1:maxlen);
    }
    return 0;
}
