#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = {1,2,3,4,5};
    //in this method we are storing the first element in x and then shifting all the elements and copying x back in place.
    // int x = arr[4]; 
    // for(int i=3;i>=0;i--)
    // {
    //     arr[i+1] = arr[i];
    // }
    // arr[0] = x;


    //in this we are using swaping.
    int a =0,b = 4;

    while(a != b)
    {
        swap(arr[a],arr[b]);
        a++;
    }

    for(int i = 0; i<5;i++)
    {
        cout<<arr[i]<<"  ";
    }
}