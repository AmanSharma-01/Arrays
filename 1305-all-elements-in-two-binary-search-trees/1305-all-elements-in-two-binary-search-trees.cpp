class Solution {
public:
//     class BSTIterator {
//     public:
//         BSTIterator(TreeNode* root) {
//             for (; root; root = root->left) {
//                 m_stk.push(root);
//             }
//         }

//         TreeNode* next() {
//             if (m_stk.empty()) {
//                 return nullptr;
//             }

//             TreeNode* node = m_stk.top();
//             m_stk.pop();

//             for (TreeNode* root = node->right; root; root = root->left) {
//                 m_stk.push(root);
//             }

//             return node;
//         }
//     private:
//         stack<TreeNode*> m_stk;
//     };
    void inorder(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> ans1;
        vector<int> ans2;
        inorder(root1, ans1);
        inorder(root2, ans2);
        
        int n = ans1.size()+ans2.size();
        vector<int> ans(n);
        
        merge(ans1.begin(), ans1.end(), ans2.begin(), ans2.end(), ans.begin());
        
        return ans;
        
//         vector<int> ret;

//         BSTIterator itr1(root1), itr2(root2);
//         TreeNode* node1 = itr1.next();
//         TreeNode* node2 = itr2.next();
//         while (node1 && node2) {
//             if (node1->val < node2->val) {
//                 ret.push_back(node1->val);
//                 node1 = itr1.next();
//             }
//             else if (node1->val == node2->val) {
//                 ret.push_back(node1->val);
//                 ret.push_back(node2->val);
//                 node1 = itr1.next();
//                 node2 = itr2.next();
//             }
//             else {
//                 ret.push_back(node2->val);
//                 node2 = itr2.next();
//             }
//         }

//         BSTIterator& itr = node1 ? itr1 : itr2;
//         for (TreeNode* node = (node1 ? node1 : node2); node; node = itr.next()) {
//             ret.push_back(node->val);
//         }

//         return ret;
    }
};