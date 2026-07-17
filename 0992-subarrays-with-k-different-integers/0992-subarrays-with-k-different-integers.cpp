class Solution {
public:
    int fun(vector<int> &nums, int k){
        int n = nums.size();
        unordered_map<int, int> mpp;
        int l = 0, r = 0, count=0;
        for(r; r<n; r++){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            count += r-l+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};