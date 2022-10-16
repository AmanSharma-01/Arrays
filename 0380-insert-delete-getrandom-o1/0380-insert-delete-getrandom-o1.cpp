class RandomizedSet {
public:
    vector<int> ans;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        ans.push_back(val);
        mp[val] = ans.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        mp[ans[ans.size()-1]] = mp[val];
        swap(ans[ans.size()-1], ans[mp[val]]);
        ans.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int pos = rand() % ans.size();
        return ans[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */