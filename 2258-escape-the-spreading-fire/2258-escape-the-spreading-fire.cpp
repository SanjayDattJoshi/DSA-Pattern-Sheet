class Solution {
public:

    void updateFireTime(vector<vector<int>> &grid, vector<vector<int>> &fireTime){
        int n = fireTime.size();
        int m = fireTime[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m,false));
        queue<pair<int, int>> q;
        int curTime = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) {
                    visited[i][j] = true;
                    fireTime[i][j] = curTime;
                    q.push({i,j});
                }
                else if(grid[i][j]==2) fireTime[i][j] = -1;
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            curTime++;
            while(size--){
                auto p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                for(int i=0; i<4; i++){
                    int newr = dr[i] + r;
                    int newc = dc[i] + c;
                    if(newr>=0 && newr<n && newc>=0 && newc<m && !visited[newr][newc] && grid[newr][newc]==0){
                        fireTime[newr][newc] = curTime;
                        visited[newr][newc] = true;
                        q.push({newr, newc});
                    }
                }
            }
        }
    }

    bool isPossible(int mid, vector<vector<int>> &fireTime){
        int n = fireTime.size();
        int m = fireTime[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));

        queue<pair<int, int>> q;
        int curTime = mid;

        if(fireTime[0][0]<=curTime) return false;

        q.push({0,0});
        visited[0][0] = true;
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        while(!q.empty()){
            curTime++;
            int size = q.size();
            while(size--){
                auto p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                for(int i=0; i<4; i++){
                    int newr = dr[i] + r;
                    int newc = dc[i] + c;

                    if(newr>=0 && newr<n && newc>=0 && newc<m && !visited[newr][newc] && fireTime[newr][newc] != -1){
                        if(newr==n-1 && newc==m-1 && curTime<=fireTime[newr][newc]) return true;

                        if(curTime< fireTime[newr][newc]){
                            visited[newr][newc] = true;
                            q.push({newr, newc});
                        }
                    }
                }

            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> fireTime(n, vector<int>(m,1e9));
        updateFireTime(grid,fireTime);

        int ans = -1;
        int low = 0, high = m*n + 1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(mid, fireTime)){
                low = mid + 1;
                ans = mid;
            }
            else high  = mid-1;
        }
        return ans == m*n+1?1e9:ans;
    }
};