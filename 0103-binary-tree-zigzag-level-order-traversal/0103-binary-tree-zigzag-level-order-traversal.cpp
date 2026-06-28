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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (!root) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        bool ltr = true;

        while (!q.empty()) {

            int levelSize = q.size();
            vector<int> ans(levelSize);

            for (int i = 0; i < levelSize; i++) {

                TreeNode* node = q.front();
                q.pop();

                int index = ltr ? i : levelSize - 1 - i;
                ans[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(ans);
            ltr = !ltr;
        }

        return res;
    }
};