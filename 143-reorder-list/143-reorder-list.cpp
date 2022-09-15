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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        
        ListNode *fast=head, *slow=head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = fast ? slow->next : slow;
        
        stack<ListNode*> st;
        while(mid) {
            st.push(mid);
            mid=mid->next;
        }
        
        ListNode* curr = head;
        ListNode* temp;
        
        while(!st.empty()) {
            temp=curr->next;
            curr->next = st.top();
            st.top()->next = temp;
            curr=temp;st.pop();
        }
        slow->next=NULL;
    }
};