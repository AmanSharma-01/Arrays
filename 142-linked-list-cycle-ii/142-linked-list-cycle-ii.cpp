/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head, *slow=head, *temp=head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast==slow) {
                while(slow!=temp) {
                    temp=temp->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};