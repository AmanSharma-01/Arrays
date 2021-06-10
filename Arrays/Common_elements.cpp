// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
#include<bits/stdc++.h>
using namespace std;

vector<int> findCommon(int a[],int n, int b[],int m, int c[], int l) 
{
    int i=0,j=0,k=0;
    vector<int> ans;
    while(i<n && j<m && k<l)
    {
        while(i>0 && i<n && a[i-1] == a[i])
        {
            i++;
        }
        while(j>0 && j<m && b[j-1] == b[j])
        {
            j++;
        }
        while(k>0 && k<l && c[k-1] == c[k])
        {
            k++;
        }
        if(i<n && j<m && k<l)
        {
            if(a[i] == b[j] && b[j] == c[k])
            {
                ans.push_back(a[i]);
                i++;
                j++;
                k++;
            }
            else if(a[i]<b[j]) i++;
            else if(b[j]<c[k]) j++;
            else k++;
        }
    }
    return ans;
}

int main()
{
    int n1 = 6; 
    int A[] = {1, 5, 10, 20, 40, 80};
    int n2 = 5;
    int B[] = {6, 7, 20, 80, 100};
    int n3 = 8;
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> a = findCommon(A,n1,B,n2,C,n3);

    int x = a.size();
    for(int i =0; i< x; i++)
    {
        cout<<a[i]<<"  ";
    }

}