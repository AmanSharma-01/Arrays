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
        ListNode *fast=head, *slow=head, *p1=head;
        
        while(fast && fast->next) {
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow == fast) {
                while(p1!=slow) {
                    slow=slow->next;
                    p1=p1->next;
                }
                return p1;
            }
        }
        
        return NULL;
    }
};