// You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets.
// A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings.
// We can make an unbalanced string balanced by swapping adjacent characters. 
// Calculate the minimum number of swaps necessary to make a string balanced.
// Note - Strings S1 and S2 can be empty.

#include<bits/stdc++.h>
using namespace std;

int countSwap(string s)
{
    int rightBracket=0,leftBracket=0;
    int swaps=0,imb=0;

    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '[')
        {
            leftBracket++;
            if(imb > 0)
            {
                swaps += imb;
                imb--;
            }
        }
        else if(s[i] == ']')
        {
            rightBracket++;
            imb = rightBracket - leftBracket;
        }
    }
    return swaps;
}

int main()
{
    string s = "[][][][][]][";
    cout << countSwap(s);
    return 0;
}