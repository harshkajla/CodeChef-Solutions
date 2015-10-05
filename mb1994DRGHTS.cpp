#include<algorithm>
#include<stdio.h>
#define max max<double>
using namespace std;
 
int main() {
	int t;
	long long T1,t1,T2,t2;
 
	scanf("%d",&t);
 
	while(t--) {
		scanf("%lld %lld %lld %lld", &T1,&T2,&t1,&t2);
 
		if(T1 == T2) {
			double a = max(0,(T1+0.0-t2))*max(0,(T1+0.0-t2))/2.0;
			a += max(0,(T2+0.0-t1))*max(0,(T2+0.0-t1))/2.0;
			a/=(T1+0.0)*(T2+0.0);
			a=1-a;
			printf("%8lf\n",a);
		}
 
		else {
		    if(T1<T2) {
		        swap(T1,T2);
		        swap(t1,t2);
		    }
		    
			double a = max(0.0,T2-t1+0.0)*max(0.0,T2-t1+0.0)/2.0;
			
			if(T2 + t2 < T1) {
			    a += (T1-T2-t2+T1-t2+0.0)*T2/2.0;
			}
			else {
			    a += max(0.0,T1-t2+0.0)*max(0.0,T1-t2+0.0)/2.0;
			}
			a/=(T1+0.0)*(T2+0.0);
			a=1-a;
			printf("%8lf\n",a);
		}
	}
	return 0;
}
