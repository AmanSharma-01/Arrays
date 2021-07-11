// C++ program to find a pair with given sum x.
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
};

void pairSum(struct Node *head, int x)
{
	struct Node* start = head;
	struct Node* end = head;

    while(end->next!=NULL)
        end=end->next;

    int flag = 0;

    while(start != end && end->next != start)
    {
        if(start->data + end->data == x)
        {
            flag = 1;
            cout<<"("<<start->data<<", "<<end->data<<")";
            start=start->next;
            end=end->prev;
        }
        else
        {
            if(start->data + end->data < x)
                start=start->next;
            else
                end=end->prev;
        }
    }
    if(flag == 0) 
        cout<<"No pair found";
}

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node;
	temp->data = data;
	temp->next = temp->prev = NULL;
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

int main()
{
	struct Node *head = NULL;
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);
	int x = 7;

	pairSum(head, x);

	return 0;
}