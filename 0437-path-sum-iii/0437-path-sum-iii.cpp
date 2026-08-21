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
    int fun(TreeNode* root, long long runningSum, int target, unordered_map<long long,int> &map){
        if(root==nullptr) return 0;

        runningSum += root->val;
        int count = map[runningSum-target];
        map[runningSum]++;

        count += fun(root->left, runningSum, target, map)
                +fun(root->right, runningSum, target, map);

        map[runningSum]--;
        return count;
    }
    int pathSum(TreeNode* root, int sum) {
        unordered_map<long long, int> preSum;
        preSum[0] = 1;
        return fun(root, 0, sum, preSum);
    }
};