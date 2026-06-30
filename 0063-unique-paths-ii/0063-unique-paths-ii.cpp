class Solution {
int fun(vector<vector<int>> &grid,vector<vector<int>>&dp, int i, int j){
    if(i==grid.size() || j==grid[0].size()) return 0;
    if(grid[i][j] == 1) return 0;
    if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int left = fun(grid,dp, i, j+1);
    int down = fun(grid,dp, i+1, j);
    return dp[i][j] = left + down;
}
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return fun(grid,dp, 0, 0);
    }
};