#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

 //this is not the full code if u want to run it go to interview bit Merge Overlapping Intervals prolem.
 bool sortit(Interval a,Interval b)
 {
    return a.start<b.start;
 }
vector<Interval> merge(vector<Interval> &A) {

    int n = A.size();
    vector<Interval> ans;
    sort(A.begin(),A.end(),sortit);
    int j = 0;
    ans.push_back(A[0]);

    for(int i =1; i<n; i++) 
    {
        if(A[i].start <= ans[j].end()) 
            ans[j].end = max(ans[j].end(), A[i].end());
        else
            {
                j++;
                ans.push_back(A[i]);
            }
    }
    return ans;

}

int main() {

}