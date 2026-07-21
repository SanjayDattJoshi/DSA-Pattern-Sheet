class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int a=0; a<n; a++){
            for(int b = a+1; b<n; b++){
                set<long long> hashSet;
                for(int c = b+1; c<n; c++){
                    long long sum = nums[a] + nums[b];
                    sum += nums[c];
                    long long d = target - sum;
                    if(hashSet.find(d) != hashSet.end()){
                        vector<int> temp = {nums[a], nums[b], nums[c], (int)d};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashSet.insert(nums[c]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};