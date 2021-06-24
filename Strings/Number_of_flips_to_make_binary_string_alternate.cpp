// Given a binary string, that is it contains only 0s and 1s.
// We need to make this string a sequence of alternate characters by flipping some of the bits,
// our goal is to minimize the number of bits to be flipped.

#include<bits/stdc++.h>
using namespace std;

int flip(char exp)
{
    return exp == '0' ? '1' : '0';
}

int abcd(string str, int exp)
{
    int flipCount = 0;
    for(int i=0;i<str.length(); i++)
    {
        if(str[i] != exp) flipCount++;
        exp = flip(exp);
    }
    return flipCount;
}

int minFlip(string str)
{
    return min(abcd(str, '0'), abcd(str, '1'));
}

int main()
{
    string str = "0001011111";
    cout << minFlip(str);
    return 0;
}