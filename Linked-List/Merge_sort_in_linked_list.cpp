#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source, Node** frontRef, Node** backRef);

void MergeSort(Node** headRef)
{
    Node* cur = *headRef;
    Node* a;
    Node* b;

    if(cur == NULL || cur->next == NULL) return;

    FrontBackSplit(cur, &a, &b);

    MergeSort(&a);
    MergeSort(&b);
    SortedMerge(a,b);
}

Node* SortedMerge(Node* a, Node* b)
{
    Node* ans = NULL;

    if(a == NULL) return (b);
    else if (b == NULL) return (a);

    if(a->data <= b->data) 
    {
        ans = a;
        ans->next = SortedMerge(a->next, b);
    }
    else
    {
        ans = b;
        ans->next = SortedMerge(a, b->next);
    }
    return ans;
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    Node* res = NULL;
    Node* a = NULL;

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    MergeSort(&a);

    cout << "Sorted Linked List is: \n";
    printList(a);

    return 0;
}