//Kahn's Algorithm

class Solution {

  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V,0);
        vector<vector<int>> adjList(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> res;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            for(auto it: adjList[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return res;
    }
};


//DFS Solution

class Solution {
  public:
  void dfs(vector<vector<int>> &adjList, vector<int> &vis, int node, stack<int> &st){
      vis[node] = 1;
      for(auto it: adjList[node]){
          int neigh = it;
          if(!vis[neigh]) dfs(adjList, vis, neigh, st);
      }
      st.push(node);
      return;
  }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
        }
        
        stack<int> st;
        vector<int> vis(V,0);
        vector<int> res;
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(adjList, vis, i, st);
        }
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};
