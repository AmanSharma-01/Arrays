// Given an unsorted array Arr of size N of positive integers. 
// One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
// Find these two numbers.

#include <bits/stdc++.h>
using namespace std;

vector<int>repeatedNumber(const vector<int> &A) 
{
    long long int len = A.size();
    long long int sum_n = (len*(len+1))/2, sum_n2 = (len*(len+1)*(2*len +1))/6;
    long long int missingNumber=0, repeating=0;

    for(int i=0;i<A.size(); i++)
    {
        sum_n -= (long long int)A[i];
        sum_n2 -= (long long int)A[i]*(long long int)A[i];
    }
    missingNumber = (sum_n + sum_n2/sum_n)/2;
    repeating= missingNumber - sum_n;
    vector<int> ans;
    ans.push_back(missingNumber);
    ans.push_back(repeating);
    return ans;
}

int main()
{
    std::vector<int> v = {4, 3, 6, 2, 1, 6,7};
    vector<int> res = repeatedNumber(v);
    for(int x: res){
        cout<< x<<"  ";
    }
    cout<<endl;
}