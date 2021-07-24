// C++ program for Minimum swap required
// to convert binary tree to binary search tree
#include<bits/stdc++.h>
using namespace std;

// Inorder Traversal of Binary Tree
void inorder(int a[], vector<int> &v,int n, int index)
{
    if(index>=n) return;
    inorder(a,v,n,2*index + 1);
    v.push_back(a[index]);
    inorder(a,v,n,2*index + 2);
}

int minSwaps(vector<int> &v)
{
	vector<pair<int,int>> ar(v.size());
    int ans=0;
    for(int i=0;i<v.size();i++) ar[i] = {v[i],i};
    sort(ar.begin(), ar.end());

    for(int i=0; i<v.size(); i++)
    {
        if(ar[i].second == i) continue;
        else
        {
            ans++;
            swap(ar[i],ar[ar[i].second]);
            i--;
        }
    }
    
    return ans;
}

int main()
{
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
	vector<int> v;
	inorder(a, v, n, 0);
	cout << minSwaps(v) << endl;
}