// Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.
#include<bits/stdc++.h>
using namespace std;

vector<int> computelps(string s3)
{
    int n = s3.length();
    vector<int> lps(n);
    
    lps[0] = 0;
    int i=1;
    int len=0;

    while(i<n)
    {
        if(s3[i] == s3[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else
        {
            if(len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int minimunCharcter(string str)
{
    string s2 = str;
    reverse(s2.begin(), s2.end());

    string s3 = str + "$" + s2;

    vector<int> lps = computelps(s3);

    return(str.length() - lps.back());
}

int main()
{
    string str = "BABANA";
    cout<<minimunCharcter(str);
    return 0;
}