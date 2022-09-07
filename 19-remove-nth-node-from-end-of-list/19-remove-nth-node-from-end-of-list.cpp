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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while(temp) {
            temp=temp->next;
            size++;
        }
        if(size == n) return head->next;
        temp=head;
        int i = size-n-1;
        while(i-- && temp->next) {
            temp = temp->next;
        }
        temp->next=temp->next->next;
        
        return head;
//         ListNode* first=head, *second=head;
//         while(n--) {
//             first = first->next;
//         }
//         if(!first) return head->next;
//         while(first->next) {
//             first=first->next;
//             second = second->next;
//         }
//         second->next = second->next->next;
        
//         return head;
    }
};