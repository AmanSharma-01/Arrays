class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0, high=arr.size()-1;
        
        while(high-low+1 > k) {
            if(abs(arr[high]-x) < abs(x-arr[low])) low++;
            else high--;
        }
        
        return vector<int> (arr.begin()+low, arr.begin()+high+1);
    }
};