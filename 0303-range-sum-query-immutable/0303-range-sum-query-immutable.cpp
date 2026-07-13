class NumArray {
    vector<int> prefixSum;
    int n;
    void preSum(vector<int> &nums){
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }
    }
    int preResult(int left, int right){
        if(left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left-1];
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        prefixSum.resize(n);
        preSum(nums);
    }
    
    int sumRange(int left, int right) {
        return preResult(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */