// C++ program to return first node of loop.
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int key;
    struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
 
Node* detectAndRemoveLoop(Node* head)
{
    Node* x;
    Node* x2;
    x=head;
    x2=head;
    int flag=0;
    while(x2!=NULL && x2->next!=NULL)
    {
        x=x->next;
        x2=x2->next->next;
        if(x == x2)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        x=head;
        while(x!=x2)
        {
            x=x->next;
            x2=x2->next;
        }
        return x;
    }
    return NULL;
}
 
int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    Node* res = detectAndRemoveLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;
 
    return 0;
}