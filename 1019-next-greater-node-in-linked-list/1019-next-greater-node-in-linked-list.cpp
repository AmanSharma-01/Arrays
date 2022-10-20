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
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 1;
        ListNode* curr = head;
        while(curr) {
            curr=curr->next;
            n++;
        }
        vector<int> ans(n-1, 0);
        stack<pair<int, int>> st;
        curr=head;
        int i=1;
        
        while(curr && i<n) {
            while(!st.empty() && curr->val > st.top().first) {
                ans[st.top().second-1] = curr->val;
                st.pop();
            }
            st.push({curr->val, i});
            curr=curr->next;
            i++;
        }
        
        return ans;
    }
};