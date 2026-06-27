class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adjList(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> vis(V,0);
        vector<int> res(V,-1);
        res[src] = 0;
        vis[src] = 1;
        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();
            for(auto it: adjList[node.first]){
                if(!vis[it]){
                    q.push({it, node.second+1});
                    res[it] = node.second+1;
                    vis[it] = 1;
                }
            }
        }
        return res;
    }
};
