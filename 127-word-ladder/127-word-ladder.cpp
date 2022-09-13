class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int len=0;
        
        while(!q.empty()) {
            for(int i=q.size();i;i--) {
                string temp = q.front();q.pop();
                if(temp == endWord) return len+1;
                for(int j=0;j<temp.size();j++) {
                    char ch = temp[j];
                    for(int k=0;k<26;k++) {
                        temp[j]=k+'a';
                        if(s.find(temp) != s.end()) {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                    temp[j]=ch;
                }
            }
            len++;
        }
        return 0;
    }
};