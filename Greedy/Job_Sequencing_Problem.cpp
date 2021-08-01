
// C++ Program to find the maximum profit job sequence from a given array of jobs with deadlines and profits
#include<bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int deadLine, profit;
};

bool cmp(Job a, Job b)
{
    return (a.profit > b.profit);
}

int printJobScheduling(Job arr[], int n)
{
    sort(arr, arr+n, cmp);
    bool done[n] = {0};

    int jobDone = 0, profit = 0;

    for(int i=0;i<n;i++)
    {
        for(int j = min(n, arr[i].deadLine - 1); j>=0;j--)
        {
            if(done[j] == false)
            {
                jobDone += 1;
                profit += arr[i].profit;
                done[j] = true;
                break;
            }
        }
    }
    cout<<"number of jobs done "<<jobDone<< " with a profit of "<<profit;
}

// Driver code
int main()
{
    Job arr[] =  { { 'a', 2, 100 }, { 'b', 1, 19 }, { 'c', 2, 27 },  { 'd', 1, 25 }, { 'e', 3, 15 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following jobs need to be "
         << "executed for maximum profit\n";
    printJobScheduling(arr, n);
    return 0;
}
