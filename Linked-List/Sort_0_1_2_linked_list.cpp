// CPP Program to sort a linked list 0s, 1s
// or 2s by changing links
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* next;
};

Node* newNode(int data);

Node* sortList(Node* head)
{
	if(!head || !head->next)
        return head;

    Node* zeroCurr = newNode(0);
    Node* oneCurr = newNode(0);
    Node* twoCurr = newNode(0);

    Node *zero = zeroCurr, *one = oneCurr,*two= twoCurr;

    Node *curr  = head;
    while(curr)
    {
        if(curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
            curr=curr->next;
        }
        else if(curr->data == 1)
        {
            one->next = curr;
            one = one->next;
            curr=curr->next;
        }
        else
        {
            two->next = curr;
            two = two->next;
            curr=curr->next;
        } 
    }

    zero->next = (oneCurr->next) ? (oneCurr->next) : twoCurr->next;
    one->next = twoCurr->next;
    two->next = NULL;

    head = zeroCurr->next;

    delete(zeroCurr);
    delete(oneCurr);
    delete(twoCurr);
    
    return head;
}

Node* newNode(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
}

void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main(void)
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(0);
	head->next->next->next = newNode(1);

	printf("Linked List Before Sorting\n");
	printList(head);

	head = sortList(head);

	printf("Linked List After Sorting\n");
	printList(head);

	return 0;
}
