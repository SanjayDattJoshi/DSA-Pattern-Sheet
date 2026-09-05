class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int>adj[], vector<vector<int>> &bridges, int tin[], int low[]){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,vis,adj,bridges,tin,low);
                low[node] = min(low[node], low[it]);

                if(low[it] > tin[node]) bridges.push_back({it, node});
            }

            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<int> adj[n];

        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);

        int tin[n], low[n];

        vector<vector<int>> bridges;

        dfs(0,-1,visited,adj,bridges,tin,low);

        return bridges;
    }
};