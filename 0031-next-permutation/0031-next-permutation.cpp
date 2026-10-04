class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return;

        int ind = -1;
        for(int i=n-1; i>0; i--){
            if(arr[i-1]<arr[i]){
                ind = i-1;
                break;
            }
        }
        if(ind != -1){
            int swapInd = ind;
            for(int i=n-1; i>ind; i--){
                if(arr[i]>arr[ind]){
                    swapInd = i;
                    break;
                }
            }
            swap(arr[ind], arr[swapInd]);
        }
        reverse(arr.begin()+ind+1, arr.end());
    }
};