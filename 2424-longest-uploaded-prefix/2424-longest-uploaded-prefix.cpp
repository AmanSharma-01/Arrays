class LUPrefix {
public:
    vector<bool> dp;
    int latest;
    LUPrefix(int n) {
        dp.resize(n+1, false);
        latest=0;
    }
    
    void upload(int video) {
        dp[video]=true;
        if(latest==video-1) {
            while(dp[video] && video<dp.size()) {
                latest=video;
                video++;
            }
        }
    }
    
    int longest() {
        return latest;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */