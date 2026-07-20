class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int res = arr[0], curMax = arr[0], curMin=arr[0];
        for(int i=1; i<n; i++){
            int v1 = curMax * arr[i];
            int v2 = arr[i];
            int v3 = curMin*arr[i];
            curMin = min({v1,v2,v3});
            curMax = max({v1,v2,v3});
            res = max(res, curMax);
        }
        return res;
    }
};