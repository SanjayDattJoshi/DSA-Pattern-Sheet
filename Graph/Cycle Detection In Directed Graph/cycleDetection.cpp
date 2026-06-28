class Solution {
  public:
  bool dfs(vector<vector<int>> &adjList, vector<int> &vis,vector<int> &path, int node){
      path[node] = 1;
      vis[node] = 1;
      for(int neigh : adjList[node]){

        if(!vis[neigh]){
            if(dfs(adjList, vis, path, neigh))
                return true;
        }
        else if(path[neigh]){
            return true;
        }
    }

    path[node] = 0;
    return false;
  }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
        }
        vector<int> path(V,0);
        vector<int> vis(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i] && dfs(adjList, vis,path, i)) return true;
        }
        return false;
    }
};
