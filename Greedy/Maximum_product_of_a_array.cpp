// CPP program to find maximum product of a subset.
#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int a[], int n)
{
    if (n == 1)
        return a[0];
    
    int zeroCount = 0;
    int negCount = 0;
    int maxNeg = INT_MIN;
    int product = 1;

    for(int i=0;i<n;i++)
    {
        if(a[i] == 0)
        {
            zeroCount++;
            continue;
        }

        if(a[i]<0)
        {
            negCount++;
            maxNeg = max(maxNeg, a[i]);
        }
        product = product * a[i];
    }
    if(negCount % 2 == 1)
    {
        if (negCount == 1 && zeroCount > 0 && zeroCount + negCount == n)
            return 0;
        
        product = product/maxNeg;
    }
    return product;
}

int main()
{
	int a[] = { -1, -1, -2, 4, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << maxProductSubset(a, n);
	return 0;
}
