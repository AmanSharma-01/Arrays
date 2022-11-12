/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* curr=head;
        while(curr) {
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr=curr->next->next;
        }
        curr=head;
        while(curr&&curr->next) {
            curr->next->random=curr->random ? curr->random->next : NULL;
            curr=curr->next->next;
        }
        
        Node *org = head, *copy = head->next, *curro = head, *currc=head->next;
        
        while(curro) {
            curro->next = curro->next->next;
            currc->next = currc->next ? currc->next->next : NULL;
            curro=curro->next;
            currc=currc->next;
        }
        return copy;
    }
};