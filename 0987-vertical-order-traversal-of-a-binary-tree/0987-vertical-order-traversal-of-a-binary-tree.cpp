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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr) return {};

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0, 0}});

        map<int, map<int,multiset<int>>> mpp;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int level = p.second.first, vertical = p.second.second;

            mpp[vertical][level].insert(node->val);

            if(node->left) q.push({node->left, {level+1, vertical-1}});
            if(node->right) q.push({node->right, {level+1, vertical+1}});
        }

        vector<vector<int>> res;

        for(auto p: mpp){
            vector<int> col;
            for(auto q: p.second) col.insert(col.end(), q.second.begin(), q.second.end());

            res.push_back(col);
        }
        return res;
    }
};