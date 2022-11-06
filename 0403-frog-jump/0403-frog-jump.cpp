class Solution {
private:
    unordered_map<int,bool> mp;
    bool canJump(vector<int>& stones, int jump, int pos, map<pair<int,int>,bool>& memo) {
        int n = stones.size();
        if(mp[pos]==false || pos > stones[n-1]) return false;
        if(pos == stones[n-1]) return true;
        if(memo.find({pos, jump}) != memo.end()) return memo[{pos, jump}];
        
        bool isPossible=false;
        
        if(pos==0) {
            isPossible = canJump(stones, 1, pos+1, memo);
        } else {
            if(jump-1 > 0) {
                isPossible = canJump(stones, jump-1, pos+(jump-1), memo);
            }
            if(isPossible) return true;
            isPossible = canJump(stones, jump, pos+(jump), memo);
            if(isPossible) return true;
            isPossible = canJump(stones, jump+1, pos+(jump+1), memo);
            if(isPossible) return true;
        }
        return memo[{pos, jump}] = isPossible;
    }
    
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for(auto itr : stones) mp[itr] = true;
        map<pair<int,int>,bool> memo;
        return canJump(stones, 1, 0, memo);
    }
};