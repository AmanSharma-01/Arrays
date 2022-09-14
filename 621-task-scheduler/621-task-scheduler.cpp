class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq=0;
        int countWithMaxFreq=0;
        for(auto task: tasks) {
            freq[task-'A']++;
            maxFreq = max(maxFreq, freq[task-'A']);
        }
        for(int i=0;i<26;i++) {
            if(freq[i]==maxFreq) countWithMaxFreq++;
        }
        
        
        return (maxFreq-1)*(n+1)+countWithMaxFreq < tasks.size() ? tasks.size() : (maxFreq-1)*(n+1)+countWithMaxFreq;
    }
};