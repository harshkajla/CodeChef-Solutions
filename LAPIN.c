/*CODECHEF.Lapindrome is defined as a string which when split in the middle, gives two halves having the same characters and same frequency of each character. If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency. Also, abccab, rotor and xyzxy are a few examples of lapindromes. Note that abbaab is NOT a lapindrome. The two halves contain the same characters but their frequencies do not match. 
Your task is simple. Given a string, you need to tell if it is a lapindrome.
Input:
First line of input contains a single integer T, the number of test cases.
Each test is a single line containing a string S composed of only lowercase English alphabet.
Output:
For each test case, output on a separate line: "YES" if the string is a lapindrome and "NO" if it is not.
Constraints:
1 = T = 100
2 = |S| = 1000, where |S| denotes the length of S
Example:
Input:
6
gaga
abcde
rotor
xyzxy
abbaab
ababc
Output:
YES
NO
YES
YES
NO
NO*/
#include<stdio.h>
int main()
{  int t,l,i,f,alpha[26];char str[1000];
    scanf("%d",&t);
    
    while(t--)
    {            f=0;//flag
    
                 //accepting string
                 scanf("%s",str);
                 
                 //initialising frequencies.
                 for(i=0;i<26;i++)
                 alpha[i]=0;
                 
                 //first half frequencies.
                 l=strlen(str);
                 for(i=0;i<l/2;i++)
                 alpha[str[i]-'a']++;
                 
                 //second half frequencies.
                 if(l%2!=0)
                 i=l/2+1;
                 
                 for(;i<l;i++)
                 {
                              //checking firsthand if it is already 0 frequency.
                              if(alpha[str[i]-'a']==0)
                              {printf("NO\n");        //unmatched letters checked.
                              f=1;
                              break;
                              }
                 
                 alpha[str[i]-'a']--;
                 }
                 
                 if(f==1)
                 continue;
                 
                 f=0;
                 //checking frequency negation.
                 for(i=0;i<l/2;i++)
                 {
                                   if(alpha[str[i]-'a']!=0)
                                   {printf("NO\n");
                                    f=1;
                                    break;
                                  }
                 
                 }
                 if(f==0)
                 printf("YES\n");
                 }     
return 0;
}
