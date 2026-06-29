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
        vector<int> dp(n+2,0);
        dp[n] = 1;
        for(int i=n-1; i>=0; i--){
            int ways = dp[i+1] + dp[i+2];
            dp[i] = ways;
        }
        return dp[0];
    }
};