//simple count and say
//you will be given a number A and find the Ath number in the sequence.
// 1, 11, 21, 1211, 111221, 312211, 13113321, ...

#include<bits/stdc++.h>
using namespace std;

string countAndSay(int a)
{
    string ans = "1";
    if(a==1) return ans;
    int count = 1;
    a--;
    while(a--)
    {
        string temp="";
        ans+='@';
        int n=ans.length();
        for(int i =0; i<n-1; i++) 
        {
            if(ans[i] == ans[i+1]) count++;
            else {temp+=count+'0';temp+=ans[i];count=1;}
        }
        ans=temp;
    }
    return ans;
}

int main()
{
    int a;
    cin>>a;
   string an = countAndSay(a);

    int x = an.length();
    for(int i=0;i<x;i++)
    {
        cout<<an[i]<<" ";
    }
}