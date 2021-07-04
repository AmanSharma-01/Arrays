// Given a number n. 
// The task is to find the smallest number whose factorial contains at least n trailing zeroes.

#include<bits/stdc++.h>
using namespace std;

bool check(int a, int mid)
{
    int temp = mid,f=5,count=0;

    while(f<= temp)
    {
        count+=temp/f;
        f=f*5;
    }
    return (count>=a);
}

int findNum(int a)
{
    if(a==1) return 5;

    int low= 0,high=5*a;

    while(low<high)
    {
        int mid = (low+high)>>1;

        if(check(a,mid)) high = mid;
        else low = mid +1;
    }
}

int main()
{
    int n = 6;
    cout << findNum(n) << endl;
    return 0;
}