class Solution {
  public:
  bool cycle = false;
  
  void dfs(vector<vector<int>> &adjList, int V, int node, int parent, vector<int> &vis){
      vis[node] = 1;
      for(int i=0; i<adjList[node].size(); i++){
          int neigh = adjList[node][i];
          if(vis[neigh] && neigh != parent)
            cycle = true;
        
          if(!vis[neigh]) dfs(adjList, V, neigh, node, vis);
      }
      return;
  }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjList(V);
        vector<int> vis(V,0);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(edges[i][1]);
            adjList[v].push_back(edges[i][0]);
        }
        
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(adjList, V, i, -1, vis);
        }
        return cycle;
    }
};
