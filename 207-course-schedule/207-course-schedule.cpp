class Solution {
public:
    
//     bool canComplete(int course, unordered_map<int, vector<int>>& mp, vector<bool>& visited, vector<bool>& completed) {
//         if(completed[course]) return true;
//         if(visited[course]) return false;
        
//         visited[course] = true;
//         for(auto nc: mp[course]) {
//             if(canComplete(nc, mp, visited, completed)) continue;
//             else return false;
//         }
//         completed[course] = true;
//         return true;
//     }
    
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        
        int n = prerequisites.size();
        unordered_map<int, vector<int>> mp;
        vector<int> count(num+1, 0);
        queue<int> q;
        int res=0;
        
        for(int i=0;i<n;i++) {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            count[prerequisites[i][0]]++;
        }
        
        for(int i=0;i<num;i++) {
            if(count[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            res++;
            int top = q.front();q.pop();
            for(auto nc: mp[top]) {
                count[nc]--;
                if(count[nc]==0) q.push(nc);
            }
        }
        return res==num;
        
        
//         int n = prerequisites.size();
//         unordered_map<int, vector<int>> mp;
//         vector<bool> visited(num+1, false);
//         vector<bool> completed(num+1, false);
        
//         for(int i=0;i<n;i++) {
//             mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
//         }
        
//         for(int i=0;i<num;i++) {
//             if(canComplete(i, mp, visited, completed)) continue;
//             else return false;
//         }
//         return true;
    }
};