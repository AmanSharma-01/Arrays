#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int minJumps(int a[], int n)
{
    if(n<=1) return 0;
    if(a[0] == 0) return -1;

    int count = 1;
    int s = a[0];
    int m = a[0];
    int i = 1;

    for(i;i<n;i++)
    {
        if(i == n-1) return count;
        m = max(m, a[i] + i);
        s--;
        if(s == 0) 
        {
            count++;
            if(i>=m) return -1;
            s = m-i;
        }
    }
    return -1;

}

int main()
{
    int arr[] = { 1, 2, 3, 3, 9, 2, 6, 7, 6, 8, 9 };
    int size = sizeof(arr) / sizeof(int);
    cout << ("Minimum number of jumps to reach end is %d ",
             minJumps(arr, size));
    return 0;
}//time complixty of this code in O(n) as it only traverse the array once.