class Solution {
public:
    unordered_map<string,
        priority_queue<string,
                       vector<string>,
                       greater<string>>> adj;

    vector<string> ans;

    void dfs(string u) {

        while(!adj[u].empty()) {

            string v = adj[u].top();
            adj[u].pop();

            dfs(v);
        }

        ans.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};