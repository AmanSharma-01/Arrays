//code a program to give the next permutation of a given number.
#include<bits/stdc++.h>
using namespace std;

void findNext(vector<int> str, int n)
{
    int k,i;
    for(k=n-2;k>=0;k--)
    {
        if(str[k]<str[k+1]) break;
    }

    if(k<0) 
    {
        reverse(str.begin(), str.end());
    }
    else 
    {
        for(i=n-1;i>k;i--)
        {
            if(str[i]>str[k]) break;
        }
        swap(str[i],str[k]);
        reverse(str.begin()+k+1, str.end());
    }

    for(int j=0;j<str.size(); j++)
    {
        cout<<str[j]<<" ";
    }
}

int main()
{
    vector<int> vect{1,2,3,6,5,4};
    int n = vect.size();
    findNext(vect, n);
    return 0;
}