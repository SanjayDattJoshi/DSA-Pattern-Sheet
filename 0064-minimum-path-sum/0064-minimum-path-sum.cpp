class Solution {
public:
    int pathSum(vector<vector<int>>&arr, int row, int col,vector<vector<int>>&dp){
        if(row==arr.size()-1 && col == arr[0].size()-1) return arr[row][col];
        if(row>=arr.size() || col >= arr[0].size()) return INT_MAX;
        if(dp[row][col] != -1) return dp[row][col];
        int sum1 = INT_MAX, sum2 = INT_MAX;
        if(col+1<arr[0].size()) sum1 =  pathSum(arr,row,col+1,dp);
        if(row+1<arr.size()) sum2 =  pathSum(arr,row+1,col,dp);
        return dp[row][col] = arr[row][col] + min(sum1, sum2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n==1 && m == 1) return grid[n-1][m-1];
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return pathSum(grid,0,0,dp);
    }
};