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
    TreeNode* build(int preSt, int preEnd, int postSt, vector<int> &pre, vector<int> &post){
        if(preSt>preEnd) return nullptr;
        TreeNode* node = new TreeNode(pre[preSt]);
        if(preSt==preEnd) return node;
        int nextNode = pre[preSt+1];

        int ind = mpp[nextNode];
        int num = ind - postSt + 1;

        node->left = build(preSt+1, preSt+num, postSt, pre, post);
        node->right = build(preSt+num+1, preEnd, ind+1 ,pre, post);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0; i<postorder.size(); i++) mpp[postorder[i]] = i;
        return build(0,preorder.size()-1,0,preorder,postorder);
    }
};