// C++ program to find the smallest
// window containing all characters
// of a pattern.
#include <bits/stdc++.h>
using namespace std;

const int MAX_CHARS = 256;

string findSubString(string str)
{
	int n = str.length();
    if(n<=1) return str;

    int d_count = 0;
    bool abc[MAX_CHARS] = {false};
    for(int i=0;i<n;i++)//counts the no. of distinct char in the string.
    {
        if(abc[str[i]] == false)
        {
            abc[str[i]] = true;
            d_count++;
        }
    }

    int s=0,s_index=-1,min_len = INT_MAX;
    int current_count[MAX_CHARS] = {0};
    int count =0;//count distinct char in current window.

    for(int i=0;i<n;i++)
    {
        current_count[str[i]]++;

        if(current_count[str[i]] == 1)
        {
            count++;
        }

        if(count == d_count)
        {
            while(current_count[str[i]] > 1)
            {
                if(current_count[str[i]] > 1)
                    current_count[str[i]]--;
                s++;
            }
            int len = i-s+1;//current window length.
            if(len<min_len)
            {
                min_len = len;
                s_index = s;
            }
        }
    }

    return str.substr(s_index, min_len);
}

int main()
{
	string str = "aabcbcdbca";
	cout << "Smallest window containing all distinct"
			" characters is: "
		<< findSubString(str);
	return 0;
}
