class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int curMax = arr[0], maxSum = arr[0];
        for(int i=1; i<n; i++){
            curMax = max(arr[i], curMax+arr[i]);
            maxSum = max(curMax, maxSum);
        }
        return maxSum;
    }
};