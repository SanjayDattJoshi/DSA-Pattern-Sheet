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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y) return false;
        unordered_map<int, pair<int, int>> levels;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto p = q.front();
                q.pop();

                TreeNode* node = p.first;
                TreeNode* parent = p.second;

                if(parent) levels[node->val] = {level, parent->val};

                if(node->left) q.push({node->left, node});
                if(node->right) q.push({node->right, node});
            }
            level++;
        }

        if(levels[x].first == levels[y].first && levels[x].second != levels[y].second) return true;
        return false;
    }
};