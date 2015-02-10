#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;
#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define DREP(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define INDEX(a, val) (lower_bound(all(a), val) - a.begin())
const int INF = 1000000000;
const int max_n = 100000;
const int max_q = 100000;
const int max_b = 100000000;
/* O(Q logN + N log N) time complexity solution:
 * for each [L, R] query, find the match that is slowest among [0, L) (= t1), [L, R] (= t2), (R, N) (= t3)
 * as well as the fastest in [L, R] (= t)
 * Now the solution is merely, t + max(t1, t3, (t2-t1)/2)
 *
 * Finding these mins and maxes is done by a segment tree, hence the logN time per operation
 */
int N, Q;
int L[max_q], R[max_q];
int b[max_n];
struct segT
{
	//min Segment Tree
	int beg[4 * max_n];
	int end[4 * max_n];
	int val[4 * max_n];
	
	void init(int pos, int start, int finish)			//initialize the subtree rooted at "pos" with a start and finish as described
	{
		beg[pos] = start;
		end[pos] = finish;
		val[pos] = INF;
		
		if(start < finish)
		{
			int mid = (start + finish) >> 1;
			int left = pos << 1;
			int right = left + 1;
			
			init(left, start, mid);
			init(right, mid+1, finish);
		}
	}
	
	void update(int ind, int x, int pos)				//update the value at array index "ind" with value 'x', located under subtree at pos
	{
		if(beg[pos] == ind && end[pos] == ind)
		{	
			val[pos] = x;
			return;
		}
		
		if(beg[pos] > ind || end[pos] < ind)			//ind is not in the subtree
			return;
		
		int left = pos << 1;
		int right = left + 1;
		
						//ind is in just one subtree, but we call the function recursively anyway
		update(ind, x, left);
		update(ind, x, right);
		val[pos] = min(val[left], val[right]);			
	}
	
	int query(int pos, int start, int finish)
	{
		if(beg[pos] >= start && end[pos] <= finish)			//interval completely contained in query interval
			return val[pos];
		if(beg[pos] > finish || end[pos] < start)
			return INF;		//identity of "min" function
		
		int left = pos << 1;
		int right = left + 1;
		
		return min(query(left, start, finish), query(right, start, finish));
	}
};
segT pos, neg;
void preprocess()
{
	
}
bool input()
{
	s(N); assert(N >= 1 && N <= max_n);
	for(int i = 0; i < N; i++)
	{
		s(b[i]);
		assert(b[i] >= 1 && b[i] <= max_b);
	}
	s(Q); assert(Q >= 1 && Q <= max_q);
	for(int i = 0; i < Q; i++)
	{
		s(L[i]);
		s(R[i]);
		assert(0 <= L[i] && L[i] <= R[i] && R[i] < N);
	}
	return true;
}
void solve()
{
	pos.init(1, 0, N-1);
	neg.init(1, 0, N-1);
	for(int i = 0; i < N; i++)
	{
		pos.update(i, b[i], 1);
		neg.update(i, -b[i], 1);					//neg is to give us our "maximum" queries
	}
	
	bool leftmost = false, rightmost = false, leftandright = false;
	for(int i = 0; i < Q; i++)
	{
		/* testing purposes
		leftmost = leftmost || L[i] == 0;
		rightmost = rightmost || R[i] == N-1;
		leftandright = leftandright || (L[i] == 0 && R[i] == N-1); */
		int back = pos.query(1, L[i], R[i]);
		int f1 = -neg.query(1, 0, L[i]-1);
		int f2 = -neg.query(1, L[i], R[i]);
		int f3 = -neg.query(1, R[i]+1, N-1);
		double front = max(f1 / 1.0, max((f2 - back) / 2.0, f3 / 1.0));
		printf("%.1lf\n", back + front + 0.01);		//+0.01 to avoid any precision issues - answer will always be .0 or .5
	}
	//cerr << leftmost << " " << rightmost << " " << leftandright << endl;
}
int main()
{
	preprocess();
	input();
	solve();
}
