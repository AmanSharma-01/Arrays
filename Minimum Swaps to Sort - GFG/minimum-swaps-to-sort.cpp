//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    using pi = pair<int, int>;
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int ans=0;
	    int n = nums.size();
	    vector<pi> temp;
	    for(int i=0;i<n;i++) {
	        temp.push_back({nums[i], i});
	    }
	    sort(temp.begin(), temp.end());
	    
	    for(int i=0;i<n;i++) {
	        if(temp[i].second == i) continue;
	        else {
	            ans++;
	            swap(temp[i], temp[temp[i].second]);
	            i--;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends