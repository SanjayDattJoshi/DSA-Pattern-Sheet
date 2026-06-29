class Solution {
public:
bool fun(vector<int>& arr, int ind, int sum, vector<vector<int>>& dp) {

        if(ind == 0){
        if(sum == arr[0]) return true;
        return false;
        
        if (sum == 0) return true;

        }
        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        bool notTake = fun(arr, ind - 1, sum, dp);

        bool take = 0;
        if (arr[ind] <= sum)
            take = fun(arr, ind - 1, sum - arr[ind], dp);

    return dp[ind][sum] = (take || notTake);
}


public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) totalSum += nums[i];

        if(totalSum%2==0){
            int s = totalSum/2;
            vector<vector<int>> dp(n, vector<int>(s+1, -1));
            return fun(nums, n-1,s, dp);
        }

        return false;
    }
};