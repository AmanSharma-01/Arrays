/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* curr = head;curr;curr=curr->next) {
            if(curr->child) {
                Node* temp = curr->next;
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
                Node* secondHead = curr->next;
                while(secondHead->next) secondHead = secondHead->next;
                secondHead->next = temp;
                if(temp) temp->prev = secondHead;
            }
        }
        
        return head;
    }
};