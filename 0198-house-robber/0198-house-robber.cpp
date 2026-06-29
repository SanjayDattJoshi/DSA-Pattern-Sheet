class Solution {
//Recursive Solution
// int fun(int i, int n, vector<int> &arr){
//     if(i>n) return 0;
//     if(i==n) return arr[n];
//     int rob = arr[i] + fun(i+2, n, arr);
//     int skip = fun(i+1, n, arr);
//     return max(rob,skip);
// }
//function call - fun(0,nums.size()-1, nums);


//Memoization
int fun(vector<int> &dp,int i, int n, vector<int> &arr){
    if(i>n) return 0;
    if(i==n) return arr[n];
    if(dp[i] != -1) return dp[i];
    int rob = arr[i] + fun(dp,i+2, n, arr);
    int skip = fun(dp,i+1, n, arr);
    return dp[i] = max(rob,skip);
}

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return fun(dp,0,nums.size()-1, nums);
    }
};