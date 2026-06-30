class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp;
    int len=1;
    temp.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
    }
};