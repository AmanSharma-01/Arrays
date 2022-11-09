//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    private:
    int partition(int arr[], int st, int ed, int sel) {
        int p = st;
        
        for(int i=st;i<=ed-1;i++) {
            if(arr[i]<=sel) {
                swap(arr[i], arr[p]);
                p++;
            }
        }
        swap(arr[p], arr[ed]);
        return p;
    }
    
    int quickSelect(int arr[], int l, int r, int tarInd) {
        if(l > r) return NULL;
        int par = partition(arr, l, r, arr[r]);
        
        if(par == tarInd) return arr[par];
        else if(par < tarInd) return quickSelect(arr, par+1, r, tarInd);
        return quickSelect(arr, l, par-1, tarInd);
    }
    
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int n = sizeof(arr);
        return quickSelect(arr, l, r, k-1);
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends