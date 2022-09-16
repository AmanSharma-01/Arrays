/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int n = 0;
        ListNode* curr=head, *temp=NULL;
        while(curr) {
            temp=curr;
            curr=curr->next;
            n++;
        }
        temp->next = head;
        int a = k%n;
        int move = n-a;
        while(move--) {
            temp=temp->next;
        }
        head = temp->next;
        temp->next=NULL;
        return head;
    }
};