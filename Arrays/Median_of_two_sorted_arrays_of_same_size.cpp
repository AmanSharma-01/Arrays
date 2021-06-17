// There are 2 sorted arrays A and B of size n each.
// Write an algorithm to find the median of the array obtained after merging the above 2 arrays
// (i.e. array of length 2n). The complexity should be O(log(n)).
#include<bits/stdc++.h>
using namespace std;

int getM(int ar1[],int ar2[], int n)//this approach will work in O(n) time.
{
    int i =0;
    int j =0;
    int count;
    int m1=-1,m2=-1;

    for(count=0;count<=n;count++)
    {
        if(i==n)//if all element of ar1 is smallerr then first element of ar2.
        {
            m1=m2;
            m2=ar2[0];
            break;
        }
        else if(j==n)//if all element of ar2 is smallerr then first element of ar1.
        {
            m1=m2;
            m2=ar1[0];
            break;
        }

        if(ar1[i]<=ar2[j])
        {
            m1=m2;
            m2=ar1[i];
            i++;
        }
        else 
        {
            m1 = m2;
            m2 = ar2[j];
            j++;
        }
    }
    return (m1 + m2)/2;
}

int median(int [], int);
 
int getMedian(int ar1[], int ar2[], int n)//this is a divide and conqure approach and give answer in O(logn) time.
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0]) / 2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

    int m1 = median(ar1, n);

    int m2 = median(ar2, n);

    if (m1 == m2)
        return m1;
 

    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1, ar2, n - n / 2 + 1);
        return getMedian(ar1 + n / 2, ar2, n - n / 2);
    }

    if (n % 2 == 0)
        return getMedian(ar2 + n / 2 - 1, ar1, n - n / 2 + 1);
    return getMedian(ar2 + n / 2, ar1, n - n / 2);
}
 
int median(int arr[], int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}

int main()
{
    int ar1[] = {1, 2, 3, 4, 5};
    int ar2[] = {6, 7, 8, 9, 10};
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is "
             << getMedian(ar1, ar2, n1) ;
    else
        cout << "Doesn't work for arrays"
             << " of unequal size" ;
    getchar();
    return 0;
}