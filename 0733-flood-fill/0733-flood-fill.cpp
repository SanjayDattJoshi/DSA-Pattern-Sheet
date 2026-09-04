class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int originalColor = image[sr][sc];

        if(originalColor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            for(int i=0; i<4; i++){
                int newr = dr[i] + r;
                int newc = dc[i] + c;
                if(newr>=0 && newr<n && newc>=0 && newc<m && image[newr][newc]==originalColor ){
                    q.push({newr, newc});
                    image[newr][newc] = color;
                }
            }
        }
        return image;
    }
};