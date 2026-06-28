class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adjList(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        vector<int> vis(V,0);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int node = p.second;
            int wt = p.first;
            if(vis[node] == 1) continue;
            
            vis[node] = 1;
            sum += wt;
            
            for(auto it: adjList[node]){
                int neigh = it.first;
                int w = it.second;
                if(!vis[neigh]) pq.push({w,neigh});
            }
        }
        return sum;
    }
};
