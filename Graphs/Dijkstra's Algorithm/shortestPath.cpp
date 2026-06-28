class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adjList(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        
        vector<int> res(V, 1e9);
        res[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,src});
        
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();
            if (dist > res[node]) continue;

            for (auto [neigh, w] : adjList[node]) {
                if (dist + w < res[neigh]) {
                res[neigh] = dist + w;
                pq.push({res[neigh], neigh});
                }
            }
        }
        
    return res;
    }
};
