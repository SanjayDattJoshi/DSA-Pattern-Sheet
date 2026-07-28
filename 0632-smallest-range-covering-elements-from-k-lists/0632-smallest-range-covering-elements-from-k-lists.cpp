class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxEl = INT_MIN;
        for(int i=0; i<k; i++){
            pq.push({nums[i][0], i, 0});
            maxEl = max(maxEl, nums[i][0]);
        }
        vector<int> result = {-100000, 100000};
        while(!pq.empty()){
            vector<int> cur= pq.top();
            pq.pop();
            int minEl = cur[0];
            int listIdx = cur[1];
            int idx = cur[2];

            if(maxEl - minEl < result[1] - result[0]) {
                result[0] = minEl;
                result[1] = maxEl;
            }

            if(idx+1 < nums[listIdx].size()){
                int nextEl = nums[listIdx][idx+1];
                pq.push({nextEl, listIdx, idx+1});
                maxEl = max(maxEl, nextEl);
            }
            else break;
        }
        return result;
    }
};