// C++ program to find largest
// rectangle with all 1s
// in a binary matrix
#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

int maxHist(int row[])
{
    stack<int> s;
    s.push(-1);
    int area = row[0];
    int i=0;
    int n =4;

    vector<int> l_s(n, -1);
    vector<int> r_s(n,n);
    while(i<n)
    {
        while(!s.empty() && s.top()!=-1 && row[i]<row[s.top()])
        {
            r_s[s.top()] = i;
            s.pop();
        }
        if(row[i] == row[i-1])
        {
            l_s[i] = l_s[i-1];
        }
        else 
        {
            l_s[i] = s.top();
        }
        s.push(i);
        i++;
    }
    for(int j=0;j<n;j++)
    {
        area = max(area, (r_s[j]-l_s[j]-1) * row[j]);
    }
    return area;
}

int maxRectangle(int A[][C])
{
    int result = maxHist(A[0]);

    for (int i = 1; i < R; i++) {

        for (int j = 0; j < C; j++)

            if (A[i][j])
                A[i][j] += A[i - 1][j];

        result = max(result, maxHist(A[i]));
    }

    return result;
}

int main()
{
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Area of maximum rectangle is "
         << maxRectangle(A);

    return 0;
}