// Given a boolean 2D array of n x m dimensions where each row is sorted.
//  Find the 0-based index of the first row that has the maximum number of 1's.
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
// The main function that returns index of row with maximum
// number of 1s.
int rowWithMax1s(bool arr[R][C])//NOTE:-this method will not work if the 1 are before 0 in a row.
{
    int j=C-1,m=0;
    for(int i=0;i<R;i++)
    {
        bool f = false;
        while(arr[i][j] == 1 && j>=0)
        {
            j--;
            f=true;
        }
        if(f) m=i;
    }
    if(m == 0 && arr[0][C-1] == 0) return -1;
    return m;
}

int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);
    return 0;
}
