class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        // Find first position where order breaks from left
        while(left < n - 1 && nums[left] <= nums[left + 1]) {
            left++;
        }

        // Already sorted
        if(left == n - 1)
            return 0;

        // Find first position where order breaks from right
        while(right > 0 && nums[right - 1] <= nums[right]) {
            right--;
        }

        // Find min and max in the unsorted portion
        int mn = INT_MAX;
        int mx = INT_MIN;

        for(int i = left; i <= right; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        while(left > 0 && nums[left - 1] > mn) {
            left--;
        }

        while(right < n - 1 && nums[right + 1] < mx) {
            right++;
        }

        return right - left + 1;
    }
};