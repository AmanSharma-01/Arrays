//write a code to check for the balanced parenthesis.
// {([])} => "balanced".
// ([] => "not balanced".

#include<bits/stdc++.h>
using namespace std;

bool parenthesisCheck(string str)
{
    stack<char> s;
    char a;

    for(int i=0;i<str.length(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') 
        {
            s.push(str[i]);
            continue;
        }

        if(s.empty()) return false;

        switch(str[i])
        {
            case ')': a = s.top();
                      s.pop();
                      if(a == '{' || a== '[') 
                      return false;
                      break;
            case '}': a = s.top();
                      s.pop();
                      if(a == '(' || a== '[') 
                      return false;
                      break;
            case ']': a = s.top();
                      s.pop();
                      if(a == '{' || a== '(') 
                      return false;
                      break;
        }
    }
    return(s.empty());
}

int main()
{
    string str = "(){}[]";

    if(parenthesisCheck(str))
        cout<<"balanced";
    else 
        cout<<"not balanced";
}