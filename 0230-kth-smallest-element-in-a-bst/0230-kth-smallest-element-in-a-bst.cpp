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
    int res=0;
    void inorderTraversal(TreeNode* root, int &k){
        if(root==nullptr) return;
        inorderTraversal(root->left, k);
        if (k == 0)
            return;

        k--;

        if (k == 0) {
            res = root->val;
            return;
        }
        inorderTraversal(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return 0;
        inorderTraversal(root, k);
        return res;
    }
};