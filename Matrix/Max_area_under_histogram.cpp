#include <bits/stdc++.h>
using namespace std;
 
int getMaxArea(int arr[], int n)
{
    stack<int> s;
    s.push(-1);
    int area = arr[0];
    int i=0;

    vector<int> l_s(n, -1);
    vector<int> r_s(n,n);
    while(i<n)
    {
        while(!s.empty() && s.top()!=-1 && arr[i]<arr[s.top()])
        {
            r_s[s.top()] = i;
            s.pop();
        }
        if(arr[i] == arr[i-1])
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
        area = max(area, (r_s[j]-l_s[j]-1) * arr[j]);
    }
    return area;
}
 
int main()
 {
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
      cout << "maxArea = " << getMaxArea(hist, n) << endl;
    return 0;
}