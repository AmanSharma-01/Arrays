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
    using pi = pair<int, ListNode*>;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;
        priority_queue<pi, vector<pi>, greater<pi>> q;
        for(int i=0;i<k;i++) {
            ListNode* curr = lists[i];
            if(curr) q.push({curr->val, curr});
        }
        if(q.size()==0) return NULL;
        
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        
        while(!q.empty()) {
            pi top = q.top();q.pop();
            if(top.second->next)
                q.push({top.second->next->val, top.second->next});
            curr->next = top.second;
            curr=curr->next;
        }
        curr->next=NULL;
        return head->next;
    }
};











