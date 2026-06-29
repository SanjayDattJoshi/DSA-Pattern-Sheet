class Solution {
public:
int fun(vector<int>& arr, int ind, int sum, vector<vector<int>>& dp) {

        if(ind == 0){
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
        

        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int notTake = fun(arr, ind - 1, sum, dp);

        int take = 0;
        if (arr[ind] <= sum)
            take = fun(arr, ind - 1, sum - arr[ind], dp);

        return dp[ind][sum] = (take + notTake);
}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto it: nums) totalSum += it;
        if(totalSum < abs(target) || (totalSum + target) % 2 != 0)
        return 0;

        int pos = (totalSum + target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(pos+1, -1));
        int res = 0;
        res = fun(nums, n-1,pos,dp);
        return res;
    }
};