class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int left = 0, right=0, zeroCount=0;
        while(right<n){
            if(nums[right]==0) zeroCount++;
            while(zeroCount>k){
                if(nums[left]==0) zeroCount--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};