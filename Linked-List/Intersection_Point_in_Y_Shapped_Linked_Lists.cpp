// Given two singly linked lists of size N and M, 
// write a program to get the point where two linked lists intersect each other.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* intersectPoint(Node* head1, Node* head2)
{
	Node* p1 = head1;
	Node* p2 = head2;

    if(p1 == NULL || p2 == NULL)
        return NULL;

    while(p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;

        if(p1 == p2)
            return p1;

        if(p1 == NULL)
            p1=head2;
        if(p2 == NULL)
            p2=head1;
        
    }
    return p1;
}

void print(Node* node)
{
	if (node == NULL)
		cout << "NULL";
	while (node->next != NULL) {
		cout << node->data << "->";
		node = node->next;
	}
	cout << node->data;
}

int main()
{
	Node* newNode;
	Node* head1 = new Node();
	head1->data = 10;
	Node* head2 = new Node();
	head2->data = 3;
	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;
	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;
	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;
	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;
	head1->next->next->next = NULL;
	Node* intersect_node = NULL;

	intersect_node = intersectPoint(head1, head2);

	cout << "INTERSEPOINT LIST :";

	print(intersect_node);

	return 0;
}
