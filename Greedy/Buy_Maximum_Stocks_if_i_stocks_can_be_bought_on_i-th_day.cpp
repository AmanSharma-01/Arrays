// C++ program to find maximum number of stocks that
// can be bought with given constraints.
#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int k, int price[])
{
	vector<pair<int,int> > v;
    for(int i=0;i<n;i++) v.push_back({price[i],i+1});

    sort(v.begin(), v.end());

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int pr = v[i].first;
        int st = v[i].second;

        if(pr*st <= k)
        {
            ans += st;
            k -= (pr*st);
        }
        else
        {
            ans += (k/pr);
            k -= pr*(k/pr);
        }
    }
    return ans;
}

int main()
{
	int price[] = { 10, 7, 19 };
	int n = sizeof(price)/sizeof(price[0]);
	int k = 45;

	cout << buyMaximumProducts(n, k, price) << endl;

	return 0;
}
