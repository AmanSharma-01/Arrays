//Given pointer to the head node of a linked list, 
//the task is to reverse the linked list. 
//We need to reverse the list by changing the links between nodes.

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }

    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void reverse()
    {
        Node* current = head;
        Node* prev = NULL, *front=NULL;
        while(current != NULL)
        {
            front = current ->next;
            current->next = prev;
            prev = current;
            current = front;
        }
        head = prev;
    }

};

int main()
{
    LinkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.push(4);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}