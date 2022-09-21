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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessHead = new ListNode(-1), *lessCurr = lessHead;
        ListNode *greatHead = new ListNode(-1), *greatCurr = greatHead;
        ListNode *curr = head;
        
        while(curr) {
            if(curr->val < x) {
                lessCurr->next = curr;
                lessCurr = lessCurr->next;
            } else {
                greatCurr->next = curr;
                greatCurr = greatCurr->next;
            }
            curr = curr->next;
        }
        greatCurr->next = NULL;
        lessCurr->next = greatHead->next;
        return lessHead->next;
    }
};