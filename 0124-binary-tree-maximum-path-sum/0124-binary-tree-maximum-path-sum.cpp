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
    int maxSum;

    int solve(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftGain = solve(root->left);
        int rightGain = solve(root->right);

        int pathThroughRoot = leftGain + rightGain + root->val;
        int bestOneSidePath = max(leftGain, rightGain) + root->val;
        int rootOnlyPath = root->val;

        maxSum = max({maxSum, pathThroughRoot, bestOneSidePath, rootOnlyPath});

        return max(bestOneSidePath, rootOnlyPath);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};