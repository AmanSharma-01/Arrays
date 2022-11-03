class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        for(auto ed: edges) {
            dis[ed[0]][ed[1]] = ed[2];
            dis[ed[1]][ed[0]] = ed[2];
        }
        for(int i=0;i<n;i++) dis[i][i]=0;
        
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(dis[i][k] == INT_MAX || dis[k][j] == INT_MAX) continue;
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                }
            }
        }
        
        int cityCnt = n;
        int cityNo = -1;
        
        for(int i=0;i<n;i++) {
            int cnt = 0;
            for(int j=0;j<n;j++) {
                if(dis[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            
            if(cnt <= cityCnt) {
                cityNo = i;
                cityCnt = cnt;
            }
        }
        return cityNo;
    }
};