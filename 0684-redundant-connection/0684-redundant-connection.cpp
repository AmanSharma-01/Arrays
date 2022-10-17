class UF {
public:
    vector<int> par;
    UF(int n) {
        for(int i=0;i<n;i++) {
            par.push_back(i);
        }
    }
    
    int find(int a) {
        if(par[a]==a) return a;
        return find(par[a]);
    }
    
    bool UNION(int a, int b) {
        int p1 = find(a);
        int p2 = find(b);
        if(p1==p2) return true;
        par[p1] = p2;
        return false;
    }
    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF *uf = new UF(n+1);
        for(auto edge: edges) {
            if(uf->UNION(edge[0], edge[1])) return edge;
        }
        return {};
    }
};









