class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int n = nums.size();
        int count = 0;
        int i=0;
        int pro = 1;
        for(int j=0; j<n; j++){
            pro *= nums[j];
            while(pro>=k){
                pro /= nums[i++];
            }
            count += j-i+1;
        }
        return count;
    }
};