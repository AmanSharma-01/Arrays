// C++ program to find length of the longest valid substring
#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string str)
{
	stack<int> st;
    st.push(-1);
    int result =0;

    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if(!st.empty())
                result = max(result, i-st.top());
            else
                st.push(i);
        }
    }
    return result;
}

int main()
{
	string str = "((()()";
	cout << findMaxLen(str) << endl;
	str = "()(()))))";
	cout << findMaxLen(str) << endl;
	return 0;
}
