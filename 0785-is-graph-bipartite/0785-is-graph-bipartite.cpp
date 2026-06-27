class Solution {
public:
bool bipartite = true;
void dfs(vector<vector<int>> &g, vector<int> &vis,
         vector<int> &color, int node){

    vis[node] = 1;

    for(int neigh : g[node]){

        if(!vis[neigh]){
            color[neigh] = !color[node];
            dfs(g, vis, color, neigh);

            if(!bipartite) return;
        }
        else if(color[neigh] == color[node]){
            bipartite = false;
            return;
        }
    }
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
         vector<int> vis(graph.size(),0);
         vector<int> color(graph.size(),0);
         for(int i=0; i<graph.size(); i++){
            if(!vis[i]) dfs(graph, vis,color, i);
         }
         return bipartite;
    }
};