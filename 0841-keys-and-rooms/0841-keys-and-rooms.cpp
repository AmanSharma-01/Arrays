class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, vector<int>& vis, int room) {
        if(vis[room]==1) return;
        vis[room] = 1;
        for(int i=0;i<rooms[room].size();i++) {
            dfs(rooms, vis, rooms[room][i]);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, -1);
        dfs(rooms, vis, 0);
        
        for(int i=0;i<n;i++) {
            if(vis[i]==-1) {
                return false;
            }
        }
        return true;
    }
};