class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int a;
    KthLargest(int k, vector<int>& nums) {
        a=k;
        for(auto num: nums)
            add(num);
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>a) q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */