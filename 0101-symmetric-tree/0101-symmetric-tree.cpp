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
private:
bool isMirrorTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(p==nullptr || q==nullptr) return false;
        if(p->val != q->val) return false;
        bool l = isMirrorTree(p->left, q->right);
        bool r = isMirrorTree(p->right, q->left);
        if(l==true && r==true) return true;
        return false;
    }
public:
    bool isSymmetric(TreeNode*root) {
        if(root == nullptr) return true;
        return isMirrorTree(root->left, root->right); 
    }
};