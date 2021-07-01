// Given two sorted arrays, a[] and b[], the task is to find the median of these sorted arrays,
// in O(log n + log m) time complexity, when n is the number of elements in the first array, 
// and m is the number of elements in the second array.
// This is an extension of median of two sorted arrays of equal size problem. 
// Here we handle arrays of unequal size also. 

#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int> arr1,vector<int> arr2)
{
    if(arr2.size()<arr1.size()) return findMedian(arr2, arr1);
    int n1 = arr1.size();
    int n2 = arr2.size();
    int low =0,high=n1;

    while(low<=high)
    {
        int cut1 = (low+high)>>1;
        int cut2 = (n1+n2+1)/2 - cut1;

        int left1 = cut1==0 ? INT_MIN : arr1[cut1-1];
        int left2 = cut2==0 ? INT_MIN : arr2[cut2-1];

        int right1 = cut1 == n1 ? INT_MAX : arr1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : arr2[cut2];

        if(left1<=right2 && left2 <= right1)
        {
            if((n1 + n2)%2 == 0)
            {
                return (max(left1, left2) + min(right1, right2))/2.0;
            }
            else return max(left1, left2);
        }
        else if(left1 > right2)
        {
            high = cut1 - 1;
        }
        else 
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main()
{
    vector<int> arr1 ={7,12,14,15,16};
    vector<int> arr2 ={1,2,3,4,9,11};

    cout<<findMedian(arr1,arr2);
    return 0;
}