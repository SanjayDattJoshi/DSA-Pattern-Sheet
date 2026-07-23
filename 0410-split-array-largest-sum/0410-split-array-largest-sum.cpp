class Solution {
public:
    bool helper(vector<int> &arr, int n, int groups, long long maxSum){
        long long curSum = 0;
        int g = 1;
        for(int i=0; i<n; i++){
            if(curSum + arr[i]<=maxSum) curSum += arr[i];
            else{
                g++;
                curSum = arr[i];
            }
        }
        return g<=groups;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long low = 0, high = 0, ans;
        for(auto it: nums){
            low = max(low, (long long)it);
            high += it;
        }
        if(k==1) return high;
        ans = low;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(helper(nums, n, k, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};