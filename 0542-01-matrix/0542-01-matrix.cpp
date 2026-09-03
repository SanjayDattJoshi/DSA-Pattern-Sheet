class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;

        // Put all 0s into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    q.push({i, j});
                }
                else {
                    mat[i][j] = -1;
                }
            }
        }

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int newr = row + dr[k];
                int newc = col + dc[k];

                if(newr >= 0 && newr < n &&
                   newc >= 0 && newc < m &&
                   mat[newr][newc] == -1) {

                    mat[newr][newc] = mat[row][col] + 1;

                    q.push({newr, newc});
                }
            }
        }

        return mat;
    }
};