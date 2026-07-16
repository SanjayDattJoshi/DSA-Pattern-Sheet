class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxCount = 0;
        while(right<n){
            if(nums[right]==1) {
                maxCount = max(maxCount, right-left+1);
                right++;
            }
            else{
                right++;
                left = right;
            }
        }
        return maxCount;
    }
};