// C++ program to find min sum of squares
// of characters after k removals
#include <bits/stdc++.h>
using namespace std;

int minStringValue(string str, int k)
{
	int l = str.length();
    if(k>=l) return 0;

    int frequency[26] = {0};
    for(int i=0;i<l;i++)
    {
        frequency[str[i] - 'a']++;
    }

    priority_queue<int> q;
    for(int i=0;i<26;i++)
    {
        q.push(frequency[i]);
    }

    while(k--)
    {
        int temp = q.top();
        q.pop();
        temp = temp-1;
        q.push(temp);
    }

    int result = 0;
    while(!q.empty())
    {
        int temp = q.top();
        result+= temp*temp;
        q.pop();
    }
    return result;
}

int main()
{
	string str = "abbccc"; // Input 1
	int k = 2;
	cout << minStringValue(str, k) << endl;

	str = "aaab"; // Input 2
	k = 2;
	cout << minStringValue(str, k);

	return 0;
}