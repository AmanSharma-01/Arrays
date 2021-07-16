// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;

#define N 4

bool mat[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};

int findCelebrity(bool mat[][4], int n)
{
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        st.push(i);
    }

    while(st.size()>=2)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(mat[a][b] == 1)
        {
            //a is not a celebrity.
            st.push(b);
        }
        else
        {
            //b is not a celebrity.
            st.push(a);
        }
    }
    int pot = st.top();
    for(int i=0;i<n;i++)
    {
        if(i != pot)
        {
            if(mat[i][pot]== 0 || mat[pot][i] == 1)
            {
                cout<<"no celebrity";
                return -1;
            }
        }
    }

    cout<<"the celebrity is "<<pot;
    return 0;
    
}

int main()
{
    int n = 4;
    int id = findCelebrity(mat, n);
    return 0;
}