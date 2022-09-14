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
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp = head;
        for(int i=0;i<2;i++) {
            if(!temp) return head;
            temp = temp->next;
        }
        
        ListNode *prev=NULL, *curr=head, *nxt=NULL;
        
        for(int i=0;i<2;i++) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        head->next = swapPairs(curr);
        return prev;
    }
};