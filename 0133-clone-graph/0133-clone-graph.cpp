/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;

        int val = node->val
        vector<int> neigh = node->neighbors;

        if(neigh.empty()) return new Node(val);

        queue<Node*> q;
        q.push(node);

        unordered_map<Node*, Node*> vis;
        vis[node] = nullptr;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* oldNode = q.front();
                q.pop();

                Node* newNode = new Node(oldNode->val);

                vector<Node*> neigh = oldNode->neighbors;

                for(int i=0; i<neigh.size(); i++){
                    if(mpp.find(neigh[i]) == mpp.end()){
                        Node* n = neigh[i];
                        newVc.push_back(n);
                    }
                }
            }
        }

    }
};*/
class Solution {
public:
    unordered_map<Node*, Node*> mpp;
    void dfs(Node* node, Node* clone_node){
        for(Node* n: node->neighbors){
            if(mpp.find(n) == mpp.end()){
                Node* clone = new Node(n->val);
                mpp[n] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(n,clone);
            }
            else{
                clone_node->neighbors.push_back(mpp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node* clone = new Node(node->val);

        mpp[node] = clone;

        dfs(node, clone);

        return clone;
    }
};