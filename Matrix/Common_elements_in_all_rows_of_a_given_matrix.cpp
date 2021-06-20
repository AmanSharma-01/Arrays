// A Program to prints common element in all
// rows of matrix
#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 5
 
void printCommonElements(int arr[M][N])
{
    map<int, int> mp;
    for(int j=0;j<N;j++)
    {
        mp[arr[0][j]] =1;
    }
    for(int i =1;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(mp[arr[i][j]] == i)
            {
                mp[arr[i][j]] = i+1;

                if(i == M-1 && mp[arr[i][j]] == M) cout<<arr[i][j]<<" ";
            }
        }
    }
}
 
int main()
{
    int mat[M][N] =
    {
        {1, 2, 1, 7, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
 
    return 0;
}