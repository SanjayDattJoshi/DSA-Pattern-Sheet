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
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> res(n+1, 1e9);
        res = dijkstra(n+1,times, k);

        int minTime = INT_MIN;
        for(int i=1; i<=n; i++){
            if(res[i]==1e9) return -1; 
            if(res[i]>minTime) minTime = res[i];
        }
        return minTime;
    }
};