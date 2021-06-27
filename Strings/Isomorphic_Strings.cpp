// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.

// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible 
// for every character of str1 to every character of str2 while preserving the order.

// Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    
    if(n!=m) return false;

    int c[MAX_CHARS] = {0};
    int d[MAX_CHARS] = {0};

    for(int i=0;i<n;i++)
    {
        c[str1[i]]++;
        d[str2[i]]++;

        if(c[str1[i]] != d[str2[i]]) return false;
    }
    return true;
}

int main()
{
    cout << areIsomorphic("aab", "xxy") << endl;
    cout << areIsomorphic("aaq", "xxq") << endl;
    return 0;
}