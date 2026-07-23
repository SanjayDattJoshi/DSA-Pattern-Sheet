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

        int low = INT_MAX, high = INT_MIN;
        for (int day : bloomDay) {
            low = min(low, day);
            high = max(high, day);
        }
        
        while(low<=high){
            int mid = low + (high - low)/2;
            if(helper(bloomDay, n, m,k, mid)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};