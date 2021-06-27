// Given two strings A and B, the task is to convert A to B if possible. 
// The only operation allowed is to put any character from A and insert it at front. 
// Find if it’s possible to convert the string. 
// If yes, then output minimum no. of operations required for transformation.

#include<bits/stdc++.h>
using namespace std;

int findMinimum(string s1, string s2)
{
    int count[256] = {0};
    int res=0;
    for(int i=0;i<s1.length();i++)
    {
        count[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++)
    {
        count[s2[i]]--;
    }
    for(int j=0;j<256;j++)
    {
        if(count[j]) return -1;
    }

    for(int i=s1.length()-1,j=s2.length()-1;i>=0;)
    {
        while(i>=0 && s1[i] != s2[j])
        {
            i--;
            res++;
        }
        if(i>=0)
        {
            i--;
            j--;
        }
    }
    return res;
}

int main()
{
    string s1 = "EACBD";
    string s2 = "AEBCD";

    cout<<findMinimum(s1,s2);
    return 0;
}