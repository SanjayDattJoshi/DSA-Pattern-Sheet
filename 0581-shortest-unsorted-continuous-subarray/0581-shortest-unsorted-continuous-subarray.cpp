class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end());

        int n = nums.size();

        int left = 0;

        while(left < n && nums[left] == sorted[left]) {
            left++;
        }

        if(left == n)
            return 0;

        int right = n - 1;

        while(right >= 0 && nums[right] == sorted[right]) {
            right--;
        }

        return right - left + 1;
    }
};