class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int n = arr.size();
        int sum1 = arr[0], sum2 = arr[0];
        int maxSum = arr[0], minSum = arr[0];
        for(int i=1; i<n; i++){
            sum1 = max(arr[i], sum1+arr[i]);
            sum2 = min(arr[i], sum2+arr[i]);
            maxSum = max(sum1, maxSum);
            minSum = min(sum2, minSum);
        }
        return max(maxSum, abs(minSum));
    }
};