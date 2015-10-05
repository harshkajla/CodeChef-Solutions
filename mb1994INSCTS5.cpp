#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,s;
    string str;
    cin>>t;
    
    while(t--)
    {
        cin>>s;
        cin>>str;
        
        string mini=str;
        for(int i=0;i<s;i++)
        {
            //erase the ith char
            char cc = str[i];
            string temp = str;
            temp=temp.erase(i,1);
            for(int j=0;j<s;j++)
            {
                //insert it in jth position n compare.
                string check = temp.substr(0,j) + cc + temp.substr(j);
                if(check<mini)
                mini=check;
            }
        }
        
        cout<<mini<<endl;
    }
    return 0;
}
