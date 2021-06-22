// C++ program for implementation of KMP pattern searching
// algorithm
#include <bits/stdc++.h>
using namespace std;
  
void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];

    computeLPSArray(pat, M, lps);

    for(int i=0;i<M;i++)
        cout<<lps[i]<<" ";
    
    cout<<"\n";
  
    int i=0;
    int j=0;

    while(i<N)
    {
        if(pat[j] == txt[i])
        {
            j++;
            i++;
            // cout<<"yes\n";
        }

        if(j == M)
        {
            // cout<<"no\n";
            cout<<"the pattern is found at index "<<i-j;
            j=lps[j-1];
        }

        else if(pat[j] != txt[i] && i<N)
        {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
}

void computeLPSArray(char* pat, int M, int* lps)
{
    int l=0;
    int i=1;

    lps[0]=0;

    while(i<M)
    {
        if(pat[i] == pat[l])
        {
            l++;
            lps[i]=l;
            i++;
        }
        else
        {
            if(l != 0)
            {
                l = lps[l-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
  
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}