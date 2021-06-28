// Consider a sample space S consisting of all perfect squares starting from 
// 1, 4, 9 and so on. You are given a number N, 
// you have to output the number of integers less than N in the sample space S.

#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int x)
{
    if (x == 0 || x == 1)
    return x;

    int i = 1, result = 1;
    while (result <= x)
    {
      i++;
      result = i * i;
    }
    return i - 1;
}

int main()
{

    int x = 100;
    cout << floorSqrt(x) << endl;
    return 0;
}