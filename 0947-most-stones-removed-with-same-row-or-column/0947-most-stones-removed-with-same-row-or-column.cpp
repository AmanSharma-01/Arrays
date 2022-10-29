class UnionFind {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    
public:
    int count;
    UnionFind(vector<vector<int>>& stones) {
        for(auto stone: stones) {
            int row = -(1+stone[0]);
            int col = 1+stone[1];
            parent[row]=row;
            parent[col]=col;
        }
        count = parent.size();
    }
    
    int find(int x) {
        if(parent[x] != x) parent[x]=find(parent[x]);
        return parent[x];
    }
    
    void union_(int x, int y) {
        int xPar = find(x);
        int yPar = find(y);
        if(xPar == yPar) return;
        count--;
        if(rank[xPar] < rank[yPar]) parent[xPar] = yPar;
        else if(rank[xPar] > rank[yPar]) parent[yPar] = xPar;
        else {
            parent[yPar] = xPar;
            rank[xPar] = rank[yPar]+1;
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(stones);
        for(auto& stone: stones) {
            int row = -(1+stone[0]);
            int col = 1+stone[1]; 
            uf.union_(row, col);
        }
        
        return stones.size()-uf.count;
    }
};








