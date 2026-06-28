class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>,
        greater<pair<int, int>>>q;
        q.push({0, k});
        while (!q.empty()) {
            auto it = q.top();
            int node = it.second;
            int time = it.first;
            q.pop();
            for (auto iter : adj[node]) {
                int adjN = iter.first;
                int t = iter.second;

                if (dis[adjN] > time+t) {
                    dis[adjN] = t+time;
                    q.push({t + time, adjN});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++){
            if(dis[i] == INT_MAX) return -1;     
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};