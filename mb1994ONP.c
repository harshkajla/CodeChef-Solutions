#include<stdio.h>
#define MOD 1000000
#define abs(x) x>0?x:(-x)
#define gc() getchar_unlocked()
#define read_int(n) n=0;cc=gc();while(cc<'0' || cc>'9')cc=gc();while(cc>='0' && cc<='9'){n= (n<<3)+(n<<1)+cc-48;cc=gc();}
#define pc(x) putchar_unlocked(x)
    inline void writeInt (int n)
    {
        int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
	pc('\n');
    }
int hash[3000001];
int main()
{
	int t,a,b,c,d,i,one;
	char cc;
	long long int temp,max,diff,n;
	read_int(t);
	for(i=0;i<3000001;i++)
	hash[i]=0;
	
	while(t--)
	{
		read_int(n);
		read_int(a);
		read_int(b);
		read_int(c);
		read_int(d);
		temp = d;diff=0;
		
		max=d;
		//calculate remaning values and store their count.
		for(i=0;i<n;i++)
		{
			hash[temp]++;
			temp = temp*( a*temp + b) + c;
			temp%=MOD;
			if(temp>max)max=temp;
		}
		one = 1;
		for(i=0;i<=max;i++)
		{
			if(hash[i]%2)
			{diff+=one*i;
			one=-one;
			}
			
			hash[i]=0;
		}
		
		writeInt(abs(diff));
	}
	return 0;
}
