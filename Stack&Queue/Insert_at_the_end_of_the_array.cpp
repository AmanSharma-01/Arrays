
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
stack<int> st;

void Insert_at_end(int x)
{
    if(st.empty())
    {
        st.push(x);
    }
    else
    {
        int a = st.top();
        st.pop();
        Insert_at_end(x);
        st.push(a);
    }
}

int main()
{
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    Insert_at_end(90);

    while(st.size() > 0)
    {
        cout<<st.top()<<"\n";
        st.pop();
    }
    return 0;
}
