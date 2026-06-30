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
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return fun(text1, text2,dp, 0, 0);
    }
};