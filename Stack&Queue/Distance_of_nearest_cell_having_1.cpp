// Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
// The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row 
// number and column number of the current cell and i2, j2 are the row number 
// and column number of the nearest cell having value 1.


// C++ program to find distance of nearest
// cell having 1 in a binary matrix.
#include<bits/stdc++.h>
#define MAX 500
#define N 3
#define M 4
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    // Code here
	    int n = mat.size();
	    int m = mat[0].size();
	    int i,j;
	    vector<vector<int>> ans(n,vector<int>(m, INT_MAX-1));
	    
	    queue<pair<int, int>> q;
	    
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            if(mat[i][j] == 1)
	            {
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    
	    while(q.size() != 0)
	    {
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        
	        int dx[4]= {-1,1,0,0};
	        int dy[4]= {0,0,1,-1};
	        
	        for(int j=0;j<4;++j)
	        {
	            int nx = x + dx[j];
	            int ny = y + dy[j];
	            
	            if(nx>=0 && ny>=0 && nx<n && ny<m)
	            {
	                if(ans[nx][ny]>ans[x][y]+1)
	                {
	                    ans[nx][ny] = ans[x][y]+1;
	                    q.push({nx,ny});
	                }
	            }
	        }
	    }
	    for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }   
                cout << endl;
        }
	}

int main()
{
    vector<vector<int>> mat = {{1,0,1},{1,1,0},{1,0,0}};

    nearest(mat);

    return 0;
}
