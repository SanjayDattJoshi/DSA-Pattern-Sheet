class Solution {
public:
     bool helper(vector<int> &arr, int n, int bq,int flowers, int maxDays){
        int count = 0, m=0;
        for(int i=0; i<n; i++){
            if(arr[i]<=maxDays){
                count++;
                if(count==flowers){
                    m++;
                    count = 0;
                }
            }
            else count  = 0;
        }
        return m>=bq?true:false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long neededFlowers = (long long) m*k;
        if(neededFlowers > n) return -1;

        int low = 1, high = 0, ans = INT_MAX;
        for(auto it: bloomDay) high = max(high, it);
        
        while(low<=high){
            int mid = low + (high - low)/2;
            if(helper(bloomDay, n, m,k, mid)){
                ans = min(ans, mid);
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans == INT_MAX? -1: ans;
    }
};