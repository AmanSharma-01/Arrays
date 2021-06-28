// Given an array A of N elements. Find the majority element in the array. 
// A majority element in an array A of size N is an element that appears more than N/2 times in the array.

#include <bits/stdc++.h>
using namespace std;

void findMajority(int arr[], int size)//this can be done without using extra space using moore's voting algorithm.
{
    unordered_map<int, int> m;
    for(int i = 0; i < size; i++)
        m[arr[i]]++;
    int count = 0;
    for(auto i : m)
    {
        if(i.second > size / 2)
        {
            count =1;
            cout << "Majority found :- " << i.first<<endl;
            break;
        }
    }
    if(count == 0)
        cout << "No Majority element" << endl;
}


int main() 
{ 
    int arr[] = {2, 2, 2, 2, 5, 5, 2, 3, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
     
    findMajority(arr, n); 

    return 0; 
} 