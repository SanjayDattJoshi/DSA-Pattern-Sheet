class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mpp;

        for (int x : arr) {
            mpp[x]++;
            if (mpp[x] > n / 2)
                return x;
        }

        return -1;   
    }
};