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
        vector<vector<long long>> dp(n+1, vector<long long>(m+1,0));
        dp[n-1][m-1] = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(grid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else if(i == n - 1 && j == m - 1) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};