class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int>mpp;
        int prefixSum = 0, count=0;
        mpp[0] = 1;
        for(int i=0; i<n; i++){
            prefixSum += arr[i];
            if(mpp.find(prefixSum-k) != mpp.end()) count += mpp[prefixSum-k];
            mpp[prefixSum]++;
            }
    return count;
    }
};