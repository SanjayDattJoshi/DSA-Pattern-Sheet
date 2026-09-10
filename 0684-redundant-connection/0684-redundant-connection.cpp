class Disjoint_Set {
    vector<int> size;
    vector<int> parent;

public:
    Disjoint_Set(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u, ulp_v;
        ulp_u = findParent(u);
        ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int getSize(int node) { return size[findParent(node)]; }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Disjoint_Set dsu(n);

        vector<int> edgeCount(n, 0);
        for(auto it : edges) {
            if(dsu.findParent(it[0]) == dsu.findParent(it[1])) return it;
            dsu.unionBySize(it[0], it[1]);
        }
        return {};
    }
};