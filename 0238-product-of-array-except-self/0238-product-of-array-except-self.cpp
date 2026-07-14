class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int totalProduct = 1, countZeros=0;
        for(int i=0; i<n; i++) {
            if(nums[i]==0) countZeros++;
            if(nums[i]!=0) totalProduct *= nums[i];
        }
        
        vector<int> res(n,0);
        if(countZeros>1) return res;
        else if(countZeros==1){
            for(int i=0; i<n; i++){
                if(nums[i]==0) res[i] = totalProduct;
                else res[i] = 0;
            }
            return res;
        }

        for(int i=n-1; i>=0; i--){
            res[i]  = totalProduct/nums[i];
        }
        return res;
    }
};