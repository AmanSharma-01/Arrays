//print all the permutation of a string.
//Below are the permutations of string ABC. 
// ABC ACB BAC BCA CBA CAB

#include<bits/stdc++.h>
using namespace std;

void printPermutation(string s, int l, int h)
{
    if(l == h)
    {
        cout<<s<<"\n";
    }
    else
    {
        for(int i=l;i<h;i++) 
        {
            swap(s[l], s[i]);
            printPermutation(s,l+1,h);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    string s = "ABCD";
    int l = 0;
    int h = s.size();
    printPermutation(s,l,h);
    return 0;
}