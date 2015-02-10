#include <stdio.h>
 
using namespace std;
 
int findGCD(int u, int v)
{
	int shift;
	/* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
	if (u == 0) return v;
	if (v == 0) return u;
 
	/* Let shift := lg K, where K is the greatest power of 2
	dividing both u and v. */
	for (shift = 0; ((u | v) & 1) == 0; ++shift) {
		u >>= 1;
		v >>= 1;
	}
 
	while ((u & 1) == 0)
		u >>= 1;
 
	/* From here on, u is always odd. */
	do {
		/* remove all factors of 2 in v -- they are not common */
		/*   note: v is not zero, so while will terminate */
		while ((v & 1) == 0)  /* Loop X */
			v >>= 1;
 
		/* Now u and v are both odd. Swap if necessary so u <= v,
		then set v = v - u (which is even). For bignums, the
		swapping is just pointer movement, and the subtraction
		can be done in-place. */
		if (u > v) {
			unsigned int t = v; v = u; u = t;
		}  // Swap u and v.
		v = v - u;                       // Here v >= u.
	} while (v != 0);
 
	/* restore common factors of 2 */
	return u << shift;
}
 
 
int num[100001], den[100001];
int r_num[100001], r_den[100001];
int pos[100001];
float r_value[100001];
 
int main()
{
	int case_num;
	scanf("%d", &case_num);
	char str[60];
 
	while(case_num){
		case_num--;
 
		int n;
		scanf("%d",&n);
 
        for(int j = 0; j < n; j++) {
            scanf("%s", str);
 
            int i = 0;
            int sum = 0;
            while(str[i] != '/'){
                sum=sum * 10 + (str[i] - '0');
                i++;
            }
            num[j] = sum;
 
            i++;
            sum = 0;
            while(str[i] != '\0'){
                sum = sum * 10 + (str[i] - '0');
                i++;
            }
            den[j] = sum;
        }
 
		r_value[n] = -1;
		for (int i = n - 1; i >= 0; i--){
		    r_num[i]=num[i];
            r_den[i]=den[i];
            pos[i]=i;
            int j=i+1;
 
            while(((float)r_num[i] / r_den[i]) < r_value[j])
            {
                r_num[i] = r_num[i] + r_num[j];
                r_den[i] = r_den[i] + r_den[j];
                pos[i] = pos[j];
                j = pos[i] +  1;
            }
			r_value[i] = (float)r_num[i] / r_den[i];
		}
 
		for (int i = 0; i < n; i++){
			int g = findGCD(r_num[i], r_den[i]);
			printf("%d/%d\n", r_num[i] / g, r_den[i] / g);
		}
		printf("\n");
	}
	return 0;
}
