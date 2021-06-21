// A O(n^2) time and O(1) space program to
// find the longest palindromic substring
#include <bits/stdc++.h>
using namespace std;

void printSubStr(char* str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

int longestPalSubstr1(string str)//this is a brute force approach and will take time O(n^3).
{
    int m = 1;
    int s = 0;

    for(int i=0;i<str.length();i++)
    {
        for(int j=i;j<str.length();j++)
        {
            int flag =1;
            for(int k=0;k<(j-i+1)/2; k++)
            {
                if(str[j-k] != str[i+k]) flag =0;
            }

            if(flag && j-i+1 > m)
            {
                m=j-i+1;
                s=i;
            }
        }
    }
 
    cout << "Longest palindrome substring is: ";
    printSubStr(str, s, s + m - 1);
 
    return m;
}

int longestPalSubstr(char* str)//this is an efficient approach and will take O(n^2) time.
{
    int m = 1;
    int s = 0;
    int l = strlen(str);
    int low, high;

    for(int i=1;i<l;i++)
    {
        low=i-1;
        high=i;
        while(low>=0 && high<l && str[low]==str[high])
        {
            if(high-low+1>m)
            {
                m=high-low+1;
                s = low;
            }
            low--;
            high++;
        }
        low=i-1;
        high=i+1;
        while(low>=0 && high<l && str[low]==str[high])
        {
            if(high-low+1>m)
            {
                m=high-low+1;
                s = low;
            }
            low--;
            high++;
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, s, s + m - 1);

    return m;
}

int main()
{
    char str[] = "teststring";
    cout << "\nLength is: "
         << longestPalSubstr(str)
         << endl;
    return 0;
}