class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> st;
        sort(nums2.begin(), nums2.end());
        for(auto num: nums1)
            st.insert(num);
        
        for(int i=0;i<nums2.size();i++) {
            if(st.find(nums2[i]) != st.end()) {
                ans.push_back(nums2[i]);
                while(i+1<nums2.size() && nums2[i] == nums2[i+1]) i++;
            }
        }
        return ans;
    }
};