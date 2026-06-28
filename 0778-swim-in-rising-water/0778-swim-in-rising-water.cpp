class Solution {
public:
bool bfs(vector<vector<int>> &arr, int n, int m, int t){
    int i,j;
    int dr[] = {1,-1,0,0};
    int dc[] = {0,0,1,-1};

    queue<pair<int, int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    q.push({0,0});
    vis[0][0] = 1;

    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        int r = node.first;
        int c = node.second;

        if(r==n-1 && c==m-1) return true;
        for(int k=0; k<4; k++){
            int row = r+dr[k];
            int col = c+dc[k];

            if(row>=0 && row<n && col>=0 && col<m){
                if(!vis[row][col] && t>=arr[row][col]){
                    q.push({row,col});
                    vis[row][col] = 1;
                }
            }
        }
    }
    return false;
}
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int low = grid[0][0];
        int high = grid[0][0];

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                high = max(high, grid[i][j]);
            }
        }

        int res = 0;
        while(low<=high){
            int guess = (low+high)/2;
            if(bfs(grid, n, m, guess)){
                res = guess;
                high = guess-1;
            }
            else low = guess+1;
        }
        return res;
    }
};