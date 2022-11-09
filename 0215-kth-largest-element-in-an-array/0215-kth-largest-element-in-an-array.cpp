class Solution {
private:
    
    int partition(vector<int>& nums, int st, int ed, int x) {
        int p=st;
        for(int i=st;i<=ed-1;i++) {
            if(nums[i] <= x) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[ed], nums[p]);
        return p;
    }
    
    int quickSelect(vector<int>& nums, int st, int ed, int tarInd) {
        if(st>ed) return NULL;
        int par = partition(nums, st, ed, nums[ed]);
        
        if(par == tarInd) return nums[par];
        else if(par < tarInd) return quickSelect(nums, par+1, ed, tarInd);
        return quickSelect(nums, st, par-1, tarInd);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n-1, n-k);
    }
};