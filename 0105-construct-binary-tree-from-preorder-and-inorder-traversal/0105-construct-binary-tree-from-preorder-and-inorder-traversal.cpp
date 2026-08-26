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
int ind = 0;
unordered_map<int,int> mpp;
TreeNode* fun(vector<int> &preorder, int low, int high){
    if(low>high) return nullptr;
    TreeNode* node = new TreeNode(preorder[ind++]);
    int id = mpp[node->val];
    node->left = fun(preorder, low, id-1);
    node->right = fun(preorder, id+1, high);
    return node;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        return fun(preorder, 0, inorder.size()-1);
    }
};