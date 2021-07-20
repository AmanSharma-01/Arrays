// C++ program for a Queue based approach
// to find first non-repeating character
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;


void firstnonrepeating(char str[])
{
	queue<char> q;
    int char_count[MAX_CHAR] = {0};

    for(int i=0;str[i];i++)
    {
        q.push(str[i]);
        char_count[str[i]-'a']++;

        while(!q.empty())
        {
            if(char_count[q.front()-'a']>1)
                q.pop();
            else
            {
                cout<<q.front();
                break;
            }
                
        }
        if(q.empty())
            cout<<'#';
    }
    cout<<"\n";
}

int main()
{
	char str[] = "aabcnbvcxsd";
	firstnonrepeating(str);
	return 0;
}
