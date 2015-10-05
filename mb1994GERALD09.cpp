#include<bits/stdc++.h>
using namespace std;
 
string str;
 
int bits(int x) {
    
    int ans = 0;
    while(x) {
        ans += (x&1);
        x>>=1;
    }
    return ans;
}
int main() {
    
    int t,n,k;
    cin>>t;
    
    while(t--) {
        
        cin>>n>>k;
        cin>>str;
        
        //converting bit string to number..
        int num = 0;
        for(int i = 0; i < n; i++)
        {
            num<<=1;
            
            if(str[i]=='1')
                num++;
        }
        
        //cout<<"number="<<num<<endl;
        int comb = 1<<n;
        int minflips = INT_MAX;
        int ans = num;
        
        for(int i = 0; i < comb; i++) {
            
            int temp = num^i;
            int prev = (temp&1);
            int flips = bits(i);
            int cons = 1;
            
            temp>>=1;
            
            for(int j = 1; j < n; j++) {
                if((temp&1) == prev) {
                    cons++;
                }
                else cons = 1;
                
                prev = temp&1;
                temp>>=1;
                
                if(cons > k) {
                    flips = INT_MAX;
                    break;
                }
            }
            
            //cout<<"flips="<<flips<<endl;
            if(flips < minflips) {
                minflips = flips;
                ans = num^i;
            }
        }
        
        cout<<minflips<<endl;
        string anss="";
        for(int i = 0; i < n; i++) {
            anss =  static_cast<char>((ans&1)+'0') + anss;
            ans>>=1;
        }
        cout<<anss<<endl;
    }
    return 0;
}
