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
class Solution {
public:
    TreeNode* createTree(vector<int> &pre, int &i, int upperBound){
        if(i>=pre.size()|| upperBound<pre[i]) return nullptr;
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = createTree(pre, i, root->val);
        root->right = createTree(pre, i, upperBound);
        return root; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()<=0) return nullptr;
        int i = 0;
        return createTree(preorder, i, INT_MAX);
    }
};