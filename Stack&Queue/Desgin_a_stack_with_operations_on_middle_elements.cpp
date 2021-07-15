#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    Node *prev;
    int data;
    Node *next;
    Node(int data);
};

Node ::Node(int data)
{
    prev = NULL;
    this->data = data;
    next = NULL;
}

class Stack
{
    public:
        Node *top;
        Node *mid;
        int count;

    Stack();

    void push(int data);
    int pop();
    int findMiddle();
    int deleteMiddle();
    };

Stack::Stack()
{
    count = 0;
    top = NULL;
    mid = NULL;
}

void Stack ::push(int data)
    {
        Node *curr = new Node(data);
        curr->prev = top;
        count += 1;

        if (top)
        top->next = curr;
        top = curr;

        if (count == 1)
        mid = curr;
        else if (count % 2 == 0)
        mid = mid->next;
    }

int Stack::pop()
    {
        if (count == 0)
        {
        cout << "Stack is empty\n";
        return -1;
        }

        Node *temp = top;

        int data = top->data;
        top = top->prev;
        count--;

        if (count % 2 != 0)
            mid = mid->prev;

        delete temp;
        return data;
    }

int Stack::findMiddle()
    {
        if (count == 0)
        {
        cout << "Stack is empty now\n";
        return -1;
        }

        return mid->data;
    }

int Stack::deleteMiddle()
{
    int data = mid->data;
    Node *temp = mid;

    mid->prev->next = mid->next;
    mid->next->prev = mid->prev;
    count--;

    if (count % 2 != 0)
    mid = mid->prev;
    else
    mid = mid->next;

    delete temp;

    return data;
}

int main()
{
Stack stk;
stk.push(11);
stk.push(22);
stk.push(33);
stk.push(44);
stk.push(55);
stk.push(66);
stk.push(77);

cout << "Item popped is " << stk.pop() << endl;
cout << "Item popped is " << stk.pop() << endl;
cout << "Item popped is " << stk.pop() << endl;
cout << "Middle Element is " << stk.findMiddle() << endl;
cout << "Deleted Middle Element is " << stk.deleteMiddle() << endl;
cout << "Middle Element is " << stk.findMiddle() << endl;

return 0;
}