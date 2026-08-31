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
    void inorderTraversal(TreeNode* root, vector<int> &arr){
        if(root==nullptr) return;
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return 0;
        vector<int> arr;
        inorderTraversal(root, arr);

        sort(arr.begin(), arr.end());

        return arr[k-1];
    }
};