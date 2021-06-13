#include<iostream>
using namespace std;
 
#define MAX 500
 
int multiply(int x, int res[], int res_size);
void factorial(int n)
{
    int res[MAX];

    res[0] = 1;
    int res_size = 1;

    for(int i =2;i<n;i++)
    {
        res_size = multiply(i, res, res_size);
    }
    cout<<"the factorial of given number is \n";
    for(int j = res_size -1; j>=0;j--)
    {
        cout<<res[j];
    }
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for(int i=0;i<x;i++)
    {
        int p = res[i] * x + carry;
        res[i] = p % 10;
        carry = p /10;
    }
    while(carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

int main()
{
    factorial(100);
    return 0;
}