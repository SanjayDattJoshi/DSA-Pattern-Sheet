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
    int getSize(int node) {
        return size[findParent(node)];
    }
};
class Solution {
public:
/*
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
*/
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Disjoint_Set dsu(n);
        for(auto it: edges){
            dsu.unionBySize(it[0], it[1]);
        }
        int comps = 0;
        vector<int> edgeCount(n);
        for(auto it: edges){
           edgeCount[dsu.findParent(it[0])]++;
        }

        for(int i=0; i<n; i++){
            int e = edgeCount[i];
            int v = dsu.getSize(i);

            if(e==(v*(v-1)/2)) comps++;
        }
        return comps;
    }
};