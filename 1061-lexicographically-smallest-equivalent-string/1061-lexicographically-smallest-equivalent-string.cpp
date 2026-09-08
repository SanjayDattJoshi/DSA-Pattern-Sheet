class Disjoint_Set {
    vector<int> parent;

public:
    Disjoint_Set() {
        parent.resize(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unite(char u, char v) {
        int pu = findParent(u - 'a');
        int pv = findParent(v - 'a');

        if (pu == pv) return;

        if (pu < pv)
            parent[pv] = pu;
        else
            parent[pu] = pv;
    }
};
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


        /*
        //for DFS solution-->

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
        }*/

        Disjoint_Set dsu;
        for(int i=0; i<n; i++){
            dsu.unite(s1[i], s2[i]);
        }

        string res;

        for(char ch : baseStr) {
            res += dsu.findParent(ch-'a')  + 'a';
        }
        return res;
    }
};