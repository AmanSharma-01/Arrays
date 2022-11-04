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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        
        ListNode *c1 = list1;
        ListNode *c2 = list2;
        
        while(c1 && c2) {
            if(c1->val <= c2->val) {
                curr->next = c1;
                c1=c1->next;
            } else {
                curr->next = c2;
                c2=c2->next;
            }
            curr = curr->next;
        }
        
        if(c1) curr->next = c1;
        if(c2) curr->next = c2;
        
        
        return ans->next;
    }
};







