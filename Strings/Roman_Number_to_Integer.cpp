//convert roman number to the decimal number 
// number lies between 1<=x<=3999.

#include<bits/stdc++.h>
using namespace std;

int intstring(char a) 
{
    switch(a) {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
    }
}

int covertToDecimal(string A)
{
    int n = A.length();
    int a,b;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        a = intstring(A[i]);
        b=-1;
        if(i+1<n) b = intstring(A[i+1]);
        
        if(b>a) ans-=a;
        else ans+=a;
    }
    return ans;
}

int main()
{
    string roman = "CDXCIX";
    cout<<covertToDecimal(roman);
}