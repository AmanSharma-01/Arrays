#include<bits/stdc++.h>
using namespace std;

string chooseandswap(string str)
{
    set<char> s;
    for(int i=0;i<str.length();i++) s.insert(str[i]);

    for(int i=0;i<str.length();i++)
    {
        s.erase(str[i]);
        if(s.empty()) break;

        char ch = *s.begin();

        if(ch < str[i])
        {
            char ch2 = str[i];
            for(int j=0;j<str.length();j++)
            {
                if(str[j] == ch) str[j] = ch2;
                else if(str[j] == ch2) str[j] = ch;
            }
            break;
        }
    }
    return str;
}

int main()
{
    string s = "ccab";
    string ans = chooseandswap(s);
    cout<<ans<<endl;
}