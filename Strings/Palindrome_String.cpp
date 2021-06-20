// Given a string S, check if it is palindrome or not.

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    string s = "abbbbba";
    int i =0, j=s.length()-1;
    int flag =0;

    while(i<j)
    {
        if(s[i] != s[j]) 
        {
            cout<<"not palindrome ";
            flag = 1;
            break;
        }
        i++;
        j--;
    }
    if(flag == 0) cout<<"palindrome";
}