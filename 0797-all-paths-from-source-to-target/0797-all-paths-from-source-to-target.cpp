class Solution {
public: 
    vector<vector<int>> res;
    void dfs(vector<vector<int>> &graph, int curNode, int target, vector<int> &curPath){
        curPath.push_back(curNode);
        if(curNode==target) {
            res.push_back(curPath);
            curPath.pop_back();
            return;
        }
        for(auto it: graph[curNode]){
            dfs(graph, it, target, curPath);
        }
        curPath.pop_back();
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> curPath;
        dfs(graph, 0, n-1, curPath);
        return res;
    }
};