#include<bits/stdc++.h>
using namespace std;

string romanstring ( int rem, char a, char b, char c ) 
{
    string abc="";
    if(rem==0)return "";
    else if(rem >= 1 && rem <=3) {for(int i=0;i<rem;i++) {abc+=a;} }
    else if(rem == 4) {abc=abc+a+b;}
    else if(rem == 5) {abc+=b;}
    else if(rem == 9) {abc=abc+a+c;}
    else
    {
        rem-=5;abc+=b;
        for(int i=0;i<rem;i++) {abc+=a;} 
    }
    return abc;
}

string intToRoman(int A) {
    string ans = "";
    int r = 0;
    int d = 0;
    r=A/1000;
    A=A%1000;
    //1 //5//10
    ans+=romanstring(r,'M','Z','Z');
    r=A/100;
    A=A%100;
    ans+=romanstring(r,'C','D','M');
    r=A/10;
    A=A%10;
    ans+=romanstring(r,'X','L','C');
    r=A/1;
    A=A%1;
    ans+=romanstring(r,'I','V','X');
    return ans;
}

int main()
{
    int a = 499;
    string str = intToRoman(a);
    int n = str.length();
    for(int i=0;i<n;i++)
    {
        cout<<str[i];
    }
}
