// Given a string s1 and a string s2, write a snippet to say whether s2 is a rotation of s1?
// (eg given s1 = ABCD and s2 = CDAB, return true, given s1 = ABCD, and s2 = ACBD , return false)

#include<bits/stdc++.h>
using namespace std;

bool areRotation(string s1, string s2)
{
    if(s1.length() != s2.length()) return 0;
    string temp = s1 + s1;

    int n = s1.length();
    int m = s2.length();

    for(int i=0;i<2*n; i++)//this is the code to find one string in the other string.(or needle in haystack problem).
    {
        int flag=0;
        for(int j=0;j<m;j++)
        {
            if(temp[i+j]!=s2[j])
            {
                flag=1;break;
            }
        }
        if(flag==0)return 1;
        
    }
    return 0;
}

int main()
{
    string s1 = "aabace";
    string s2 = "baceaa";

    if(areRotation(s1,s2))
    {
        cout<<"the strings are rotation";
    }
    else 
    {
        cout<<"the strings are not the rotation";
    }

}