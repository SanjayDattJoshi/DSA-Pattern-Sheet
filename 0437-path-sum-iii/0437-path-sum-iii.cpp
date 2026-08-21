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
    int fun(TreeNode* root, long long sum){
        if(root==nullptr) return 0;
        int count = 0;
        if(root->val == sum) count = 1;

        count += fun(root->left, sum - root->val);
        count += fun(root->right, sum - root->val);
        return count;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return 0;
        return pathSum(root->left, sum) + 
               pathSum(root->right, sum) +
               fun(root, sum);
    }
};