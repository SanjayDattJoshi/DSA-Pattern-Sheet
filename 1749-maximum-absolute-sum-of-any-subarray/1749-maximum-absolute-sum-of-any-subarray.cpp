class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int n = arr.size();
        int curMax = arr[0], curMin = arr[0];
        int maxSum = arr[0], minSum = arr[0];
        for(int i=1; i<n; i++){
            curMax = max(arr[i], curMax+arr[i]);
            curMin = min(arr[i], curMin+arr[i]);
            maxSum = max(curMax, maxSum);
            minSum = min(curMin, minSum);
        }
        return max(maxSum, abs(minSum));
    }
};