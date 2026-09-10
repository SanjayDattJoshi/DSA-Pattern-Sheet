class Disjoint_Set{
    vector<int> size;
    vector<int> parent;
    
public:
    Disjoint_Set(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u, ulp_v;
        ulp_u = findParent(u);
        ulp_v = findParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[], int &edges, int &nodes){
        vis[node] = 1;
        nodes++;

        edges += adj[node].size();

        for(auto it: adj[node]){
            if(vis[it] == 0) {
                dfs(it, vis, adj,edges,nodes);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n,0);
        int comps = 0;
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                int edges = 0;
                int nodes = 0;
                dfs(i, visited, adj, edges, nodes);
                edges /= 2;
                if(edges == nodes * (nodes - 1) / 2) comps++;
            }
        }
        return comps;
    }
};