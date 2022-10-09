class UF {
public:
    vector<int> par;
    
    UF(int n) {
        for(int i=0;i<n;i++) {
            par.push_back(i);
        }
    }
    
    int find(int curr) {
        if(par[curr] == curr) return curr;
        return find(par[curr]);
    }
    
    bool Union(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);
        if(p1==p2) return true;
        par[p1]=p2;
        return false;
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF *uf = new UF(n+1);
        
        for(auto edge: edges) {
            if(uf->Union(edge[0], edge[1])) return edge;
        }
        
        return {};
    }
};






