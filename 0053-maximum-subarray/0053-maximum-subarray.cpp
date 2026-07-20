class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0], curMax=nums[0];
        for(int i=1; i<n; i++){
            int val1 = curMax + nums[i];
            int val2 = nums[i];
            curMax = max(val1, val2);
            res = max(curMax, res);
        }
        return res;
    }
};