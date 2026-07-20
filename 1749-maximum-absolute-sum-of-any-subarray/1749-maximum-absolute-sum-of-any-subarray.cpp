class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int res1=arr[0], curMax= arr[0], res2=arr[0], curMin = arr[0];
        int n = arr.size();
        for(int i=1; i<n; i++){
            int v1 = curMax+arr[i];
            int v2 = arr[i];            
            curMax = max(v2, v1);
            res1 = max(res1, curMax);
            int v3 = curMin+arr[i];
            int v4 = arr[i];            
            curMin = min(v3, v4);
            res2 = min(res2, curMin);
        }
        return max(abs(res1), abs(res2));
    }
};