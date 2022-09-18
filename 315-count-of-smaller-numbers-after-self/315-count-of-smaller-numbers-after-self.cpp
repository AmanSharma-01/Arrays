class Solution {
public:
    
    void helper(vector<pair<int,int>>& arr, vector<int>& ans, int st, int ed) {
        if(ed-st <= 0) return;
        int mid = st + (ed-st)/2;
        helper(arr, ans, st, mid);
        helper(arr, ans, mid+1, ed);
        
        int j = mid+1;
        for(int i=st;i<=mid;i++) {
            while(j<=ed && arr[j].first < arr[i].first) j++;
            ans[arr[i].second] += j-(mid+1);
        }
        inplace_merge(arr.begin()+st, arr.begin()+mid+1, arr.begin()+ed+1);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++) {
            arr.push_back({nums[i], i});
        }
        helper(arr, ans, 0, n-1);
        return ans;
    }
};