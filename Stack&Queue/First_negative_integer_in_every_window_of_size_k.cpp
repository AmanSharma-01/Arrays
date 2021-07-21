// C++ implementation to find the first negative
// integer in every window of size k
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long a[],long long int n, long long int k) {
    long long int i;
    queue<long long int> q;
    vector <long long> ans;
    
    for(i=0;i<k;i++)
    {
        if(a[i]<0) q.push(a[i]);
    }
    
    if(q.size() != 0) ans.push_back(q.front());
    else ans.push_back(0);
    
    long long int j=0;
    
    for(int i=k;i<n;i++)
    {
        if(a[j]==q.front())
            q.pop();
            
        j++;
        
        if(a[i]<0) q.push(a[i]);
        
        if(q.size() != 0) ans.push_back(q.front());
        else ans.push_back(0);
    }
    return ans;
 }

int main()
{
	long long int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
	long long int n = sizeof(arr)/sizeof(arr[0]);
	long long int k = 3;
	vector<long long> answer = printFirstNegativeInteger(arr, n, k);
    long long int x = answer.size();

    for(int i=0;i<n;i++)
    {
        cout<<answer[i]<<" ";
    }

	return 0;
}
