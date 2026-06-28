class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({grid[0][0], {0,0}});

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        time[0][0] = grid[0][0];

        while(!pq.empty()){
            pair<int,pair<int, int>> node = pq.top();
            pq.pop();
            int t = node.first;
            int row = node.second.first;
            int col = node.second.second;

            if(t>time[row][col]) continue;

            for(int k=0; k<4; k++){
                int r = row + dr[k];
                int c = col + dc[k];

                if(r>=0 && r<n && c>=0 && c<m){
                    int newT = max(t, grid[r][c]);
                    if(newT<time[r][c]){
                        time[r][c] = newT;
                        pq.push({newT, {r,c}});
                    }
                }
            }
        }
    return time[n-1][m-1];
    }
};