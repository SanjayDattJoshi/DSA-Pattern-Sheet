class Solution {
public:
    typedef pair<long long, pair<int,int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        priority_queue<p, vector<p>, greater<p>> pq;
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> result;
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0,0}});
        set<pair<int,int>> vis;
        vis.insert({0,0});
        while(!pq.empty() && k--){
            auto temp = pq.top();
            int i = temp.second.first, j = temp.second.second;
            pq.pop();
            result.push_back({nums1[i], nums2[j]});
           if(i<n-1 && vis.find({i+1, j}) == vis.end()) {
            vis.insert({i+1, j});
            pq.push({nums1[i+1]+nums2[j], {i+1, j}});
           }
            
           if(j<m-1 && vis.find({i, j+1}) == vis.end()) {
            vis.insert({i, j+1});
            pq.push({nums1[i]+nums2[j+1], {i, j+1}});
           }
           
        }
        return result;
    }
};