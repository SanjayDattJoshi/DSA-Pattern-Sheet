class Solution {
public:
    char dfs(unordered_map<char, vector<char>> &adj, char ch, vector<int> &visited){
        visited[ch-'a'] = 1;
        char minChar = ch;

        for(auto &it: adj[ch]){
            if(visited[it-'a'] == 0){
                minChar = min(minChar,dfs(adj, it, visited));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();

        unordered_map<char, vector<char>> adj;

        for(int i=0; i<n; i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        string res;
        for(int i=0; i<m; i++){
            char ch = baseStr[i];

            vector<int> visited(26,0);
            char minChar = dfs(adj, ch, visited);

            res.push_back(minChar);
        }
        return res;
    }
};