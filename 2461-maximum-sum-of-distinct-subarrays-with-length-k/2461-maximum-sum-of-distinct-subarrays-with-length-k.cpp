class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum=0, sum=0;
        int left = 0, right=0;
        unordered_map<int, int> freq;
        for (right = 0; right < n; right++) {
            sum += nums[right];
            freq[nums[right]]++;

            if (right - left + 1 > k) {
                sum -= nums[left];
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }

            if (right - left + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};