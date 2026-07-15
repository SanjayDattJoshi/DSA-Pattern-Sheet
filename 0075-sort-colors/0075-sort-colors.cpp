class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeros = 0, ones = 0, twos = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) zeros++;
            else if(nums[i]==1) ones++;
            else twos++;
        }
        for(int i=0; i<n; i++){
            while(zeros--){
                nums[i] = 0;
                i++;
            }
            while(ones--){
                nums[i] = 1;
                i++;
            }
            while(twos--){
                nums[i] = 2;
                i++;
            }
        }
    }
};