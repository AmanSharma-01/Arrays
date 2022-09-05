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
        if(p1 == p2) return true;
        par[p1] = p2;
        return false;
    }
    
};




class Solution {
public:
    
    // bool canReach(int e1, int e2, unordered_map<int, vector<int>>& mp, vector<bool>& vis) {
    //     if(vis[e1]) return true;
    //     vis[e1] = true;
    //     for(auto nxt: mp[e1]) {
    //         if(nxt != e2 && canReach(nxt, e1, mp, vis)) return true;
    //     }
    //     return false;
    // }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UF* uf = new UF(n+1);
        
        for(auto i: edges) {
            if(uf->Union(i[0], i[1])) return i;
        }
        return {};
        
//         unordered_map<int, vector<int>> mp;
//         vector<bool> vis(n+1, false);
//         for(int i=0;i<edges.size();i++) {
           
//             for(int j=0;j<n+1;j++)vis[j]=false;
//             mp[edges[i][0]].push_back(edges[i][1]);
//             mp[edges[i][1]].push_back(edges[i][0]);
//             if(canReach(edges[i][0], -1, mp, vis)) return edges[i];
//         }
//         return {};
    }
};