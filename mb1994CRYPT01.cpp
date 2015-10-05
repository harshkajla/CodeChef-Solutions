#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        cin >> str;
        
        int a=0;
        char cur='-';
        for(int i = 0; i < str.size(); i++) {
            
            if(str[i]!=cur)
                a++;
                
            if(cur=='-')
                cur='+';
            else 
                cur='-';
        }
        
        cout << min(a,static_cast<int>(str.size())-a) << endl;
        
    }
    
    return 0;
}
