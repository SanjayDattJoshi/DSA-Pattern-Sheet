class Solution {
public:

    int helper(vector<int> &arr, int n, int maxW){
        int d = 1, curW=0;
        for(int i=0; i<n; i++){
           if(curW+arr[i]<=maxW) curW += arr[i];
           else{
                d++;
                curW = arr[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int totalWeight = 0, maxEle = 0;
        for(auto it: weights) {
            maxEle = max(maxEle, it);
            totalWeight += it;
        }

        int low = maxEle, high = totalWeight;
        while(low<=high){
            int mid = low + (high-low)/2;
            int d = helper(weights, n, mid);
            if(d<=days) {
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};