class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int count = 0;

        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2){
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }
        int dr[] = {0, 1, -1, 0};
        int dc[] = {1, 0, 0, -1};
        while (!q.empty() && fresh > 0) {
            count++;
            int s = q.size();
            while (s--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
                        if (grid[newr][newc] == 1) {
                            q.push({newr, newc});
                            grid[newr][newc] = -1;
                            fresh--;
                        }
                    }
                }
            }
        }
        return fresh>0 ? -1 : count;
    }
};