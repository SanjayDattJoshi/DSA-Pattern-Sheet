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
    unordered_map<int, int> mpp;
    int ind = 0;
    TreeNode* build(vector<int> &preorder, int low, int high){
        if(low>high) return nullptr;
        TreeNode* node = new TreeNode (preorder[ind++]);
        int index = mpp[node->val];
        node->left = build(preorder, low, index-1);
        node->right = build(preorder, index+1, high);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) mpp[inorder[i]] = i;
        return build(preorder, 0, preorder.size()-1);
    }
};