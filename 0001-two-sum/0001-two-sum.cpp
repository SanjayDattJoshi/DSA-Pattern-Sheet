class Solution {
public:
    vector<int> twoSum(vector<int>& nums,
    int target) {
        int n = nums.size();
        map<int, int> mymp;

        for(int i=0; i<n; i++){
            int num = nums[i];
            int moreNeeded = target - num;
            if(mymp.find(moreNeeded)  != mymp.end()){
                return { mymp [moreNeeded], i};
            }
            mymp[num] = i;
            }

            return {-1,-1};
        }
};