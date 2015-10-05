#include<stdio.h>
#include<string>
#include<limits.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    string s1,s2,newstr;
    int n,i,minshift,pos,maxl;
    
    scanf("%d",&n);
    
    cin>>s1;
    cin>>s2;
    
    minshift=INT_MAX;maxl=0;
    
    //compare prefixes of a to be a substring of b..
    //this loop adjusts the prefix length..
    for(i=0;i<n;i++)
    {
        newstr=s1.substr(0,i);
        //substring length is i..
        
        //find this string in s2..
        pos=s2.find(newstr);
        
        //if not found..break
        if(pos==string::npos)
        break;
        
        //else update the min shift required..
        else
        {  
            if(i>maxl)
            {minshift=pos;maxl=i;}
            
            else
            minshift=min(minshift,pos);
        }
    }
    
    printf("%d\n",minshift);
    return 0;
}
