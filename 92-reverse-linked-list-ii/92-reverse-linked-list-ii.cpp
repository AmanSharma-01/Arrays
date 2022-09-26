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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* leftPrev = dummy, *curr=head;
        
        for(int i=0;i<left-1;i++) {
            leftPrev=curr;
            curr=curr->next;
        }
        
        ListNode* prev=NULL, *nxt=NULL;
        
        for(int i=0;i<right-left+1;i++) {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        leftPrev->next->next=curr;
        leftPrev->next=prev;
        
        return dummy->next;
        
    }
};