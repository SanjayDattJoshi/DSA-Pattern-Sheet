class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size();

        int curMax = arr[0], res1 = arr[0];
        int curMin = arr[0], res2 = arr[0];
        int totalSum = arr[0];

        for(int i = 1; i < n; i++) {
            totalSum += arr[i];

            curMax = max(arr[i], curMax + arr[i]);
            res1 = max(res1, curMax);

            curMin = min(arr[i], curMin + arr[i]);
            res2 = min(res2, curMin);
        }

        if(res1 < 0)
            return res1;

        return max(res1, totalSum - res2);
    }
};