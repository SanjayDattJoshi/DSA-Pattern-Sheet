class Solution {
public:
void dfs(int node, vector<int> &vis, vector<vector<int>> &grid){
    vis[node] = 1;
    for(int k=0; k<grid[node].size(); k++){
            if(grid[node][k]==1 && !vis[k]){
                dfs(k, vis, grid);
            }
    }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                count++;
                dfs(i,vis,isConnected);
            }
        }
        return count;
    }
};