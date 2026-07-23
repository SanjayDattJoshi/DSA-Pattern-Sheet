class Solution {
public:
    bool helper(vector<int> &arr, int n, int dist, int baskets){
        int count = 1, last = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]-last>=dist){
                count++;
                last = arr[i];
                continue;
            }
        }
        if(count>=baskets) return true;
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1, high = position[n-1] - position[0], ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(helper(position,n,mid,m)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid-1;
        }
        return ans;
    }
};