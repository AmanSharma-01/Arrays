//code to detect a loop in a ll
//not the full code.

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        Node *x,*x2;
        x = head;
        x2 = head;
        int flag=0;
        while(x2 != NULL && x2->next != NULL)
        {
            x = x->next;
            x2 = x2->next->next;
            if(x == x2)
            {
                flag = 1;
                break;
            }
        }
        return flag;
    }
};