#include<bits/stdc++.h>
using namespace std;
int cnt[100001];
int main()
{
    int t,x,n;
    cin >> t;
    
    while(t--)
    {
    
        memset(cnt, 0, sizeof cnt); 
        int mcnt=0,ele=0;
        
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            cnt[x]++;
            
            if(cnt[x] > mcnt)
            {
                ele=x;
                mcnt=cnt[x];
            }
        }
        
        cout << n - mcnt << endl;
    }
    
    return 0;
}
