class Solution {
public:
int fun(string &s, string &p,vector<vector<int>> &dp, int ind1, int ind2){
    if(ind1>s.size()-1 || ind2>p.size()-1) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2]; 
    if(s[ind1]==p[ind2]) return dp[ind1][ind2] = 1 + fun(s,p,dp,ind1+1, ind2+1);
    int c1 = fun(s,p,dp,ind1,ind2+1);
    int c2 = fun(s,p,dp,ind1+1,ind2);
    return dp[ind1][ind2] = max(c1,c2);
}
public:
    int longestCommonSubsequence(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        for(int ind1=n-1; ind1>=0; ind1--){
            for(int ind2=m-1; ind2>=0; ind2--){
                if(s[ind1]==p[ind2]) dp[ind1][ind2] = 1 + dp[ind1+1][ind2+1];
                else{
                int c1 = dp[ind1][ind2+1];
                int c2 = dp[ind1+1][ind2];
                dp[ind1][ind2] = max(c1,c2);
                }
            }
        }
        return dp[0][0];
    }
};