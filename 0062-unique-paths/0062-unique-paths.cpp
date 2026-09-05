class Solution {
private:
int totalPaths(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up = 0, left = 0;
    up += totalPaths(arr, i - 1, j,dp);
    left += totalPaths(arr, i, j - 1,dp);
    return dp[i][j] = up + left;
}
public:
    int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j-1];
            }
        }

        return dp[n-1];
    }
};