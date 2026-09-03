class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> res(n, vector<int> (m,-1));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    res[i][j] = 0;
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;

            for(int i=0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if((newr>=0 && newr<n && newc>=0 && newc<m) && res[newr][newc]== -1){
                    res[newr][newc] = res[row][col] + 1;
                    q.push({newr, newc});
                }
            }
        }
        return res;
    }
};