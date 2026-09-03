class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
            
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        grid[0][0] = 1;

        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int pathLen = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if (row == n - 1 && col == m - 1)
                return pathLen;

            for (int i = 0; i < 8; i++) {
                int newr = dr[i] + row;
                int newc = dc[i] + col;

                if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
                    if (grid[newr][newc] == 0) {
                        q.push({pathLen + 1, {newr, newc}});
                        grid[newr][newc] = 1;
                    }
                }
            }
        }
        return -1;
    }
};