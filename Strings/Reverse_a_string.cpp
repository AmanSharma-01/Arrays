// Write a function that reverses a string. The input string is given as an array of characters s.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> s{'h','e','l','l','o'};
    int n = s.size();
        int i=0,j=n-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }

    i=0;
    while(i<=n)
    {
        cout<<s[i]<<" ";
        i++;
    }
}