class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;

        int insertInd = 2;

        for(int curInd = 2; curInd<n; curInd++){
            if(nums[curInd] != nums[insertInd-2]){
                nums[insertInd] = nums[curInd];
                insertInd++;
            }
        }
        return insertInd;
    }
};