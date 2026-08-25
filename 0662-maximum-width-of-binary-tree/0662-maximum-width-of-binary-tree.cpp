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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int ans = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            unsigned long long leftMost, rightMost;
            for(int i=0; i<size; i++){
                auto p = q.front();
                q.pop();

                TreeNode* node = p.first;
                unsigned long long index = p.second;

                if(i==0) leftMost = index;
                if(i==size-1) rightMost = index;

                if(node->left) q.push({node->left, 2*index});

                if(node->right) q.push({node->right, 2*index+1});
            }
            // unsigned long long width =;
            ans = max(ans, (int)( rightMost-leftMost+1));
        }
        return ans;
    }
};