class Solution {
int bs(vector<int> &arr, int start, int end, int t){
    int res=INT_MAX;
    int n = arr.size();
    int i=start, j=end;
    while(i<=j){
        int m = i + (j-i)/2;
        if(arr[m]==t) return m;
        else if(arr[m]>t) j = m-1;
        else i = m + 1;
    }
    return res;
}
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0,high=n-1,res=-1;
        int part = 0;
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else{
                high=mid;
            }
        }
        part = low;
        int val1 = bs(nums, 0, part-1, target);
        int val2 = bs(nums, part, n-1, target);
        res = val1==INT_MAX?val2:val1;
        return res==INT_MAX?-1:res;
    }
};