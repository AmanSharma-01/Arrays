class Solution {
public:
    
    void countLess(vector<pair<int, int>>& arr, vector<int>& ans, int st, int ed) {
        if(st>=ed) return;
        int mid = st + (ed-st)/2;
        countLess(arr, ans, st, mid);
        countLess(arr, ans, mid+1, ed);
        
        int j = mid+1;
        for(int i=st;i<=mid;i++) {
            while(j<=ed && arr[i].first>arr[j].first) j++;
            ans[arr[i].second] += j-(mid+1);
        }
        inplace_merge(arr.begin()+st, arr.begin()+mid+1, arr.begin()+ed+1);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++) {
            arr.push_back({nums[i], i});
        }
        countLess(arr, ans, 0, n-1);
        return ans;
    }
};