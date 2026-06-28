class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({0, {0,0}});

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        dis[0][0] = 0;

        while(!pq.empty()){
            pair<int,pair<int, int>> node = pq.top();
            pq.pop();
            int dist = node.first;
            int row = node.second.first;
            int col = node.second.second;

            if(dist>dis[row][col]) continue;

            for(int k=0; k<4; k++){
                int r = row + dr[k];
                int c = col + dc[k];

                if(r>=0 && r<n && c>=0 && c<m){
                    int absDiff = abs(heights[row][col]-heights[r][c]);
                    int newWt = max(absDiff, dist);
                    if(newWt<dis[r][c]){
                        dis[r][c] = newWt;
                        pq.push({newWt, {r,c}});
                    }
                }
            }
        }
    return dis[n-1][m-1];
    }
};