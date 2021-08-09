// C++ program to divide a board into m*n squares
#include <bits/stdc++.h>
using namespace std;

int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
	int ans = 0;
    sort(X, X+m, greater<int>());
    sort(Y, Y+n, greater<int>());
    int h=1,v=1;
    int i=0,j=0;

    while(i<m && j<n)
    {
        if(X[i] > Y[j])
        {
            ans += v*X[i];
            h++;
            i++;
        }
        else
        {
            ans += h*Y[j];
            v++;
            j++;
        }
    }
    int total = 0;
    while(i<m)
        total += X[i++];
    ans += total * v;

    total = 0;
    while(j<n)
        total += Y[j++];
    ans += total * h;

    return ans;
}

int main()
{
	int m = 6, n = 4;
	int X[m-1] = {2, 1, 3, 1, 4};
	int Y[n-1] = {4, 1, 2};
	cout << minimumCostOfBreaking(X, Y, m-1, n-1);
	return 0;
}
