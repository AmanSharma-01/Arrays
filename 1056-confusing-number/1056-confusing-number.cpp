class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<char, char> invertMap = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        string rotated = "";
        
        for(auto it: to_string(n)) {
            if(invertMap.find(it) == invertMap.end()) return false;
            rotated += invertMap[it];
        }
        reverse(rotated.begin(), rotated.end());
        return stoi(rotated) != n;
;    }
};