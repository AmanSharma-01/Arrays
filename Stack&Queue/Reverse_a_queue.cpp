// CPP program to reverse a Queue
#include <bits/stdc++.h>
using namespace std;

void Print(queue<int>& Queue)
{
	while (!Queue.empty()) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
}

void reverseQueue(queue<int>& Q)
{
	stack<int> st;

    while(!Q.empty())
    {
        st.push(Q.front());
        Q.pop();
    }
    while(!st.empty())
    {
        Q.push(st.top());
        st.pop();
    }
}

int main()
{
	queue<int> Queue;
	Queue.push(10);
	Queue.push(20);
	Queue.push(30);
	Queue.push(40);
	Queue.push(50);
	Queue.push(60);
	Queue.push(70);
	Queue.push(80);
	Queue.push(90);
	Queue.push(100);
    
	reverseQueue(Queue);
	Print(Queue);
}
