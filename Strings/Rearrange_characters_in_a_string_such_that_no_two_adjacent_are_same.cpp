// Given a string with repeated characters, 
// the task is to rearrange characters in a string so that no two adjacent characters are same.
// Note : It may be assumed that the string has only lowercase English alphabets.

#include<bits/stdc++.h>
using namespace std;

char maxCountChar(vector<int> &count)
{
    int max = INT_MIN;
    char ch;
    for(int i=0;i<26;i++)
    {
        if(count[i]>max) 
        {
            max = count[i];
            ch = 'a' + i;
        }
    }
    return ch;
}

string rearrangeString(string str)
{
    int n = str.length();
    if(n == 0) return ""; 

    vector<int> count(26, 0);
    for(int i=0; i<n; i++)
    {
        count[str[i]-'a']++;
    }

    char ch_max = maxCountChar(count);
    int maxCount = count[ch_max - 'a'];

    if(maxCount > (n+1) / 2) return "";

    string res(n, ' ');

    int j = 0;

    while(maxCount)
    {
        res[j] = ch_max;
        j = j+2;
        maxCount--;
    }
    count[ch_max - 'a'] = 0;

    for(int i=0;i<26;i++)
    {
        while(count[i] > 0)
        {
            j = (j>=n) ? 1:j;//if max frequency is half then the j will be over the limit and we have to set it to 1 again.
            res[j] = 'a' + i;
            j = j+2;
            count[i]--;
        }
    }
    return res;
}

int main()
{
    string str = "aaabbbb";

    string res = rearrangeString(str);
    if (res == "")
        cout << "Not valid string" << endl;
    else
        cout << res << endl;
    return 0;
}