class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++) mpp[arr[i]]++;

        int majority;
        for(int i=0; i<n; i++) if(mpp[arr[i]]>n/2) majority = arr[i];
        return majority;
    }
};