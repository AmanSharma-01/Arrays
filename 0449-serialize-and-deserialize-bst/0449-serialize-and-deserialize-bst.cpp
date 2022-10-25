/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void ser(TreeNode* root, ostringstream& o) {
        if(root) {
            o<<root->val<<" ";
            ser(root->left, o);
            ser(root->right, o);
        } else {
            o<<"# ";
        }
    }
    
    TreeNode* der(istringstream& in) {
        string val;
        in>>val;
        
        if(val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = der(in);
        root->right = der(in);
        
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream o;
        ser(root, o);
        return o.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream i(data);
        return der(i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;