// C++ program to clone a linked list with next
// and arbit pointers in O(n) time
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next,*arb;
	Node(int x)
	{
		data = x;
		next = arb = NULL;
	}
};

void print(Node *start)
{
	Node *ptr = start;
	while (ptr)
	{
		cout << "Data = " << ptr->data << ", arb = "
			<< ptr->arb->data << endl;
		ptr = ptr->next;
	}
}

Node* clone(Node *start)
{
	Node *cur = start;
    Node *temp;

    while(cur)
    {
        temp = cur->next;
        cur->next = new Node(cur->data);
        cur->next->next = temp;
        cur=temp;
    }
    cur = start;

    while(cur)
    {
        cur->next->arb = cur->arb ? cur->arb->next : cur->arb;
        cur=cur->next->next;
    }
    Node *org = start;
    Node *copy = start->next;
    temp = copy;

    while(org && copy)
    {
        org->next = org->next->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        org = org->next;
        copy=copy->next;
    }
    return temp;
}

int main()
{
	Node* start = new Node(1);
	start->next = new Node(2);
	start->next->next = new Node(3);
	start->next->next->next = new Node(4);
	start->next->next->next->next = new Node(5);

	// 1's arb points to 3
	start->arb = start->next->next;

	// 2's arb points to 1
	start->next->arb = start;

	// 3's and 4's arb points to 5
	start->next->next->arb = start->next->next->next->next;
	start->next->next->next->arb = start->next->next->next->next;

	// 5's arb points to 2
	start->next->next->next->next->arb = start->next;

	cout << "Original list : \n";
	print(start);

	cout << "\nCloned list : \n";
	Node *cloned_list = clone(start);
	print(cloned_list);

	return 0;
}
