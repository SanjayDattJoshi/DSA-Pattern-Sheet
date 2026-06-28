class Solution {
public:
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    int dr[] = {0,1,-1,0};
    int dc[] = {1,0,0,-1};
    for(int k=0; k<4; k++){
        int newr = row + dr[k];
        int newc = col+ dc[k];
        if(newr>=0 && newr<n && newc >=0 && newc<m){
            if(grid[newr][newc]=='1' && !vis[newr][newc]){
                dfs(newr, newc, vis, grid);
            }
        }
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};