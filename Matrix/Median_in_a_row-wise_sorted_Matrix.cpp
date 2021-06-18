// Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.
#include<bits/stdc++.h>
using namespace std;
//this is using binary search to find the element which have (n*m/2) elements smaller then it.

int csmall(vector<int> &r, int m)
{
    int l=0,h=r.size()-1;
    while(l<=h)
    {
        int md = (l+h)>>1;
        if(r[md]<=m) l = md +1;
        else h = md - 1;
    }
    return l;
}

int findMedian(vector<vector<int> > &A) {
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();

    while(low<=high)
    {
        int c=0;
        int mid = (low+high) >> 1;

        for(int i=0;i<n;i++)
        {
            c += csmall(A[i], mid);
        }
        if(c<=(n*m)/2) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
