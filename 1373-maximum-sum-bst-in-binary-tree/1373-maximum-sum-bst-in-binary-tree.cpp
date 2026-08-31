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

//Bruteforce
// class Solution {
// public:
//     bool isValid(TreeNode* root, long long low, long long high) {
//     if (root == nullptr)
//         return true;

//     if (root->val <= low || root->val >= high)
//         return false;

//     return isValid(root->left, low, root->val) &&
//            isValid(root->right, root->val, high);
//     }
//     int sum(TreeNode* root){
//         if(root==nullptr) return 0;
//         return sum(root->left) + sum(root->right) + root->val;
//     }

//     int maxSumBST(TreeNode* root) {
//         if(root==nullptr) return 0;

//         int ans = 0;

//         if (isValid(root, LLONG_MIN, LLONG_MAX)) {
//             ans = sum(root);
//         }

//         ans = max(ans, maxSumBST(root->left));

//         ans = max(ans, maxSumBST(root->right));

//         return ans;
//     }
// };

class Node{
    public:
    int sum;
    int minVal;
    int maxVal;
    Node(int sum,int minVal,int maxVal){
        this->sum=sum;
        this->minVal=minVal;
        this->maxVal=maxVal;
    }
};
class Solution {
public:
    int ans=0;
    Node helper(TreeNode*root){
        if(root==nullptr) return Node(0,INT_MAX,INT_MIN);
        Node left=helper(root->left);
        Node right=helper(root->right);
        if((root->val > left.maxVal) && (root->val < right.minVal)){
            int total=left.sum + right.sum + root->val;
            ans=max(ans,total);
            return Node(total,min(root->val,left.minVal),max(root->val,right.maxVal));
        }
        return Node(0,INT_MIN,INT_MAX);
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};