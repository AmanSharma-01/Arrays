// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

long long int sumArray(long long int* arr, int n)
{
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

long long int maximizeSum(long long int arr[], int n, int k)
{
	sort(arr, arr+n);
    int i=0;
    for(i=0;i<n;i++)
    {
        if(k && arr[i] < 0)
        {
            arr[i] *= -1;
            k--;
            continue;
        }
        break;
    }

    if(i == n)
        i--;

    if(k==0 || k%2 == 0) return sumArray(arr,n);

    if(i!=0 && abs(arr[i]) >= abs(arr[i-1]))
        i--;

    arr[i] *= -1;
    return sumArray(arr,n);
}

int main()
{
	int n = 5;
	int k = 4;
	long long int arr[5] = { -3, -2, -1, 5, 6 };

	cout << maximizeSum(arr, n, k) << endl;
	return 0;
}
