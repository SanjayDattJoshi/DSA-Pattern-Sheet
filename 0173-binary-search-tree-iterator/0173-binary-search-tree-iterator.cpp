/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> inorder;
    int n;
    void inorder_Traversal(TreeNode* root){
        if(root==nullptr) return;
        if(root->left)  inorder_Traversal(root->left);
        inorder.push_back(root->val);
        if(root->right) inorder_Traversal(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorder_Traversal(root);
        n = inorder.size();
    }
    int ind = 0;
    int next() {
        return inorder[ind++];
    }
    
    bool hasNext() {
        if(ind <= n-1) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */