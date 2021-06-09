#include<bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
        vector< pair <int,int> > a;
        int ans=0;
        for(int i =0;i<n;i++)
        {   
            int temp1 = arr[i]+k;
            int temp2 = arr[i]-k;
            a.push_back({temp1,i});
            a.push_back({arr[i],i});
            if(temp2>=0) a.push_back({temp2,i});
        }

        sort(a.begin(), a.end());
        //to-do(not complete).....
    }

int main()
{
   int Arr[10] = {2,6,3,4, 7, 2, 10, 3, 2, 1};

    int a = getMinDiff(Arr, 10 ,5);

    cout<<"the min. difference is  "<<a;

}