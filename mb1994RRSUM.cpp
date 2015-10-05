#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<limits.h>
#define gtc getchar_unlocked()
using namespace std;
struct block
{
    int color;
    int len;
    int start;
    int cfulness;
};
typedef struct block block;
pair<int,int> colors[21];
block blocks[20],aux[20];
vector<int> array_of_bits[262144];
int pascal[21][21];
int read_int()
{
    register int noRead=0,isneg=0;
    register char p=gtc;
    for(;p<48 || p>57;p=gtc){if(p=='-') isneg=1;}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=gtc;}
    if(isneg) noRead = -noRead;
    return noRead;
};
void Cvalues()
{
    int i,j;
    for(i=0;i<21;i++)
    {
        for(j=0;j<=i/2;j++)
        {
            if(j==0)pascal[i][i-j]=pascal[i][j]=1;
            else pascal[i][i-j]=pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }
    }
}
inline int CFN(int one, int two, int k, int sum)
{
    block b1,b2;
    int l1,l2,ans=0,c1,c2,x,i,left,right;
    b1=blocks[one];l1=b1.len;
    b2=blocks[two];l2=b2.len;
    c1=sum+l1;
    c2=c1+l2-1;
    left=b1.start;
    right=l1-1;
    while(left<=right)
    {
        x=left+k;
        if(x>=c1 && x<=c2)break;
        left++;
    }
    if(left>right)return 0;
    while(right>=left)
    {
        x=right+k;
        if(x>=c1 && x<=c2)break;
        right--;
    }
    if(right<left)return 0;
    return right-left+1;
}
int main()
{
    int t,comb,temp,i,bitno,n,k,block1,block2,j,cfn12,cfn21,sum,bj,numerator,denominator,cond,f,kk;
    vector<int>::iterator ii,begin,end;
    double ans;
    ///precomputation:
    Cvalues();
    comb=(1<<18)-1;
    for(i=0;i<=comb;i++)
    {
        temp=i;bitno=0;
        while(temp)
        {
            if(temp&1)
            array_of_bits[i].push_back(bitno);
            bitno++;
            temp>>=1;
        }
    }
    t=read_int();
    while(t--)
    {
        vector<int> pairs;
        for(i=0;i<=20;i++)colors[i].first=colors[i].second=-1;
        n=read_int();k=read_int();
        ans=0.0d;
        if(n<2)
        comb=(1<<n)-1;
        else comb=(1<<(n-2))-1;
        for(i=0;i<n;i++)
        {
            blocks[i].len=read_int();
            blocks[i].color=read_int();
            cond=(blocks[i].len>k);
            blocks[i].start=(blocks[i].len-k)*cond;
            blocks[i].cfulness=(blocks[i].start)*cond;
            if(colors[blocks[i].color].first==-1)
            colors[blocks[i].color].first=i;
            else
            {
                colors[blocks[i].color].second=i;
                pairs.push_back(blocks[i].color);
            }
            //finding contribution of single color blocks..
            ans+=(blocks[i].cfulness+0.0d);
        }
        //finding contribution of double colored blocks..
        for(vector<int>::iterator xx=pairs.begin();xx!=pairs.end();xx++)
        {
            //found a pair..
            block1=colors[(*xx)].first;
            block2=colors[(*xx)].second;
            kk=0;
            for(i=0;i<n;i++)
            {
                if(i!=block1 && i!=block2)
                aux[kk++]=blocks[i];
            }
            //for this pair..try all possible in between sums..
            for(j=0;j<=comb;j++)
            {
                begin=array_of_bits[j].begin();
                end=array_of_bits[j].end();
                f=0;sum=0;bj=array_of_bits[j].size();
                for(ii=begin;ii!=end;ii++)
                {
                    sum+=aux[(*ii)].len;
                    if(sum>(k-1))
                    {
                        f=1;break;
                    }
                }
                if(f)continue;
                //i've calculated the sum of blocks between block1 and block2..
                //now time to calculate cfn12 and cfn21
                cfn12=CFN(block1,block2,k,sum);
                numerator=cfn12<<1;
                denominator=n*pascal[n-1][bj];
                ans+=(numerator+0.0d)/(denominator+0.0d);
            }
        }
        printf("%.7lf\n",ans);
    }
    return 0;
}
