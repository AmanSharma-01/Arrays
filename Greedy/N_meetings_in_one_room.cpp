
// C++ program for activity selection problem when input activities may not be sorted.
#include <bits/stdc++.h>
using namespace std;


static bool activityCompare(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void printMaxActivities(int start[], int end[], int n)
{
    vector<pair<int,int> > ans(n);
    for(int i=0;i<n;i++) ans[i] = {start[i], end[i]};

    sort(ans.begin(), ans.end(), activityCompare);

    int i =0;
    int j =1;
    int count = 1;

    while(j<n)
    {
        if(ans[i].second < ans[j].first)
        {
            count++;
            i=j;
            j++;
        }
        else
        {
            j++;
        }
    }
    cout<<"the number of meetings are "<<count;
}

int main()
{
    int start[] = {1,3,0,5,8,5};
    int end[] =  {2,4,6,7,9,9};
    int n = sizeof(start)/sizeof(start[0]);
    printMaxActivities(start, end, n);
    return 0;
}
