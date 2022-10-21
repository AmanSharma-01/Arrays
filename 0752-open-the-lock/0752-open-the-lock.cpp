class Solution {
public:
    
    vector<string> turn(string currStr, int pos) {
        vector<string> res(2, currStr);
        res[0][pos] = '0' + ((res[0][pos]-'0')+1)%10;
        res[1][pos] = '0' + ((res[1][pos]-'0')-1+10)%10;
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end()), seen({"0000"});
        if(dead.find("0000") != dead.end()) return -1;
        if(target == "0000") return 0;
        
        queue<string> q;
        q.push("0000");
        
        int minTurns=0;
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                string top = q.front();q.pop();
                for(int j=0;j<4;j++) {
                    for(auto comb: turn(top, j)) {
                        if(dead.find(comb) == dead.end() && seen.find(comb) == seen.end()) {
                            if(comb == target) return minTurns+1;
                            else seen.insert(comb), q.push(comb);
                        }
                    }
                }
            }
            minTurns++;
        }
        return -1;
    }
};