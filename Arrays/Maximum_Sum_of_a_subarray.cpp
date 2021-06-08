#include<bits/stdc++.h>
using namespace std;

int main () {
    int arr[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max = INT_MIN;
    int sum =0;

    for(int i =0;i<9;i++)
    {
        sum+=arr[i];
        if(sum < 0) sum=0;
        else if(sum>max) max=sum;
    }
    cout<<"the maximum sum of the subarray is  "<<max<<"\n";
}