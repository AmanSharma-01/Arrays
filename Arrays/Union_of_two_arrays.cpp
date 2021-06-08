
// C++ program for the union of two arrays using Set
#include <bits/stdc++.h>
using namespace std;
void getUnion(int a[], int n, int b[], int m)//this is using sets. sets don't have any duplicate elements so we only have to insert all the elements and sets take care of the duplicates.
{
     
   set<int> s;
   for(int i =0; i<n;i++)
   {
       s.insert(a[i]);
   }
   for(int i =0; i<m;i++)
   {
       s.insert(b[i]);
   }

   for(auto itr = s.begin(); itr != s.end(); itr++)
   {
       cout<<*itr<<" ";
   }

}

void printUnion(int* a, int n, int* b, int m)//this method uses map.we know that map stores distinct keys only
{
    map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        mp.insert({a[i],i});
    }
    for(int i=0;i<m;i++)
    {
        mp.insert({b[i],i});
    }

    for(auto itr = mp.begin(); itr != mp.end(); itr++)
   {
       cout<<itr->first<<" ";
   }
}
 
int main()
{
    int a[9] = { 1, 2, 5, 6, 2, 31, 5, 7, 3 };
    int b[10] = { 2, 4, 5, 6, 8, 9, 4, 6, 5, 4 };
 
    // getUnion(a, 9, b, 10);
    printUnion(a,9,b,10);
}
 