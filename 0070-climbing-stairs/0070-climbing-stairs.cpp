class Solution {
public:
int fun(int i, int n,vector<int> &dp){
    if(i>n) return 0;
    if(i==n) return 1;
    if(dp[i] != -1) return dp[i];
    int ways = fun(i+1, n, dp) + fun(i+2, n, dp);
    return dp[i] = ways;
}
public:
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return fun(0, n,dp);
    }
};