class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n;
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        int top = maxHeap.top();maxHeap.pop();
        minHeap.push(top);
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        n++;
    }
    
    double findMedian() {
        if(n%2==0) return ((double)maxHeap.top()+(double)minHeap.top())/2;
        else return (double) maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */