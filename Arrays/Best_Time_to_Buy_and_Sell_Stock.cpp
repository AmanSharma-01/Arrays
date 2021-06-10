// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include<bits/stdc++.h>
using namespace std;

int easyWay(int arr[], int n)//this is a brute force method and takes time O(n^2).
{
    int profit = INT_MIN;
    int currentProfit = INT_MIN;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            currentProfit = arr[j] - arr[i];
            if(currentProfit > profit) profit = currentProfit;
        }
    }

    return profit < 0 ? 0 : profit;

}

int bestTime(int arr[], int n)//this is the better way to solve the same problem and the time complexity of the same is O(n).
{
    int max = 0;
    int min = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<min) min = arr[i];
        else if(arr[i] - min > max) max = arr[i] - min;
    }

    return max;

}

int main() 
{
    int arr[] = {7,6,4,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int a = bestTime(arr,n);
    cout<<"the maxmimum profit that can be achived is  "<<a;
}