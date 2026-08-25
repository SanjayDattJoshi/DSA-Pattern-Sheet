/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;

        queue<pair<Node*, int>> q;
        q.push({root,0});

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto p = q.front();
                Node* node = p.first;
                int level = p.second;
                q.pop();

                if(!q.empty() && level == q.front().second) node->next = q.front().first;
                else node->next = nullptr;

                if(node->left) q.push({node->left, level+1});
                if(node->right) q.push({node->right, level+1});
            }
        }
        return root;
    }
};