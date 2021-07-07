
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* node)
{

    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr;
    struct Node* ptr2;
    ptr=loop_node;
    ptr2=loop_node;

    int k=1;
    while(ptr->next != ptr2)
    {
        ptr = ptr->next;
        k++;
    }
    ptr=head;
    ptr2=head;

    for(int i=0;i<k;i++)
        ptr2=ptr2->next;

    while(ptr!=ptr2)
    {
        ptr=ptr->next;
        ptr2=ptr2->next;
    }

    while(ptr2->next != ptr)
        ptr2=ptr2->next;
    
    ptr2->next = NULL;
}

int detectAndRemoveLoop(struct Node* head)
{
    struct Node* x;
    struct Node* x2;
    x=head;
    x2=head;

    while(x2!=NULL && x2->next!=NULL)
    {
        x=x->next;
        x2=x2->next->next;
        if(x == x2)
        {
            removeLoop(x, head);
            return 1;
        }
    }
    return 0;
}

struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int main()
{
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;
}
