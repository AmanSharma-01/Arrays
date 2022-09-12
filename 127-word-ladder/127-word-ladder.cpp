class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wl) {
        set<string> s(wl.begin(), wl.end());
        int ladder=0;
        queue<string> q;
        q.push(beginWord);
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                string temp = q.front();q.pop();
                if(temp == endWord) {
                    return ladder+1;
                }

                for(int j=0;j<temp.size();j++) {
                    char ch = temp[j];
                    for(int k=0;k<26;k++) {
                        temp[j] = k+'a';
                        if(s.find(temp) != s.end()) {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                    temp[j]=ch;
                }
            }
            ladder++;
        }
        return 0;
    }
};