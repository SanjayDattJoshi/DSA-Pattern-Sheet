class Solution {
public:
bool bipartite = true;
void dfs(vector<vector<int>> &g,
         vector<int> &color, int node){
    if(!bipartite) return;
    for(int neigh : g[node]){
        if(color[neigh]==-1){
            color[neigh] = !color[node];
            dfs(g, color, neigh);
        }
        else if(color[neigh] == color[node]){
            bipartite = false;
            return;
        }
    }
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
         vector<int> color(graph.size(),-1);
         for(int i=0; i<graph.size(); i++){
            if (color[i] == -1) {
                color[i] = 0;
                dfs(graph, color, i);
            }
         }
         return bipartite;
    }
};