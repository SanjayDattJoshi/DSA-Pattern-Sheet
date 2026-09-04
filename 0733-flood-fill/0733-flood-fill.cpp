class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int originalColor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});

        visited[sr][sc] = true;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            image[r][c] = color;

            for(int i=0; i<4; i++){
                int newr = dr[i] + r;
                int newc = dc[i] + c;
                if(newr>=0 && newr<n && newc>=0 && newc<m && image[newr][newc]==originalColor && !visited[newr][newc]){
                    q.push({newr, newc});
                    visited[newr][newc] = true;
                }
            }
        }
        return image;
    }
};