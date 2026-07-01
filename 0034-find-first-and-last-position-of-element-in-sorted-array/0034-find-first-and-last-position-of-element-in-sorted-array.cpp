class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ind(2);
        int n = nums.size();
        int low = 0, high = n-1, i=-1,j=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                i = mid;
                high = mid-1;
            }
            else if(nums[mid]>target) high = mid-1;

            else low = mid+1;
        }
        low = 0, high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                j = mid;
                low = mid+1;
            }
            else if(nums[mid]>target) high = mid-1;
            
            else low = mid+1;
        }
        ind[0] = i;
        ind[1] = j;
        return ind;
    }
};