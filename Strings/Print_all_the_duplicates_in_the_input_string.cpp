// C++ program to count all duplicates
// from string using maps

#include <bits/stdc++.h>
using namespace std;
void printDups(string str) //map stores the characters and the no. of times it appears in the string.
{
    map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;
    }
 
    for (auto it : count) {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
                 << "\n";
    }
}

int main()
{
    string str = "this is a test string to check for the duplicates";
    printDups(str);
    return 0;
}