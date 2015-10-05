#include <bits/stdc++.h>
using namespace std;
int ans, idx, cur, pos;
string a, b;
void computeLPSArray(string pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
void KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
 
    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // idx for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // idx for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
        
        cur++;
        if (cur > ans) {
            ans = cur;
            idx = pos;
        }
      }
 
      if (j == M)
      {
        j = lps[j-1];
        return;
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
         
         cur = j;
         pos = i - j;
      }
    }
    free(lps); // to avoid memory leak
}
int main() {
    int n;
    scanf("%d", &n);
    cin >> a >> b;
    b += b;
    
    ans = 0; idx = -1; cur = 0;
    KMPSearch(a, b);
    cout << idx << endl;
}
