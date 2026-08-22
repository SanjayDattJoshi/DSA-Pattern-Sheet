/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void buildParent(TreeNode* root, TreeNode* par){
        if(root==nullptr) return;
        parent[root] = par;
        buildParent(root->left, root);
        buildParent(root->right, root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root, nullptr);
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> vis;
        vis.insert(target);
        int dist = 0;
        while(!q.empty()){
            if(dist==k) break;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left && vis.find(cur->left) == vis.end()){
                    q.push(cur->left);
                    vis.insert(cur->left);
                }
                if(cur->right && vis.find(cur->right) == vis.end()){
                    q.push(cur->right);
                    vis.insert(cur->right);
                }
                if(parent[cur] && vis.find(parent[cur]) == vis.end()){
                    q.push(parent[cur]);
                    vis.insert(parent[cur]);
                }
            }
            dist++;
        }
        vector<int> res;
        while(!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};