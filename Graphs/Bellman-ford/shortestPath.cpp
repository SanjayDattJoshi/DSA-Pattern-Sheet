class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> res(V, 1e8);
        res[src] = 0;
        for(int i=0; i<V-1; i++){
            for(auto it: edges){
                int s = it[0];
                int d = it[1];
                int w = it[2];
                
                if(res[s] != 1e8 && res[d]> res[s]+w) res[d] = res[s] + w;
            }
        }
        for(auto it: edges){
            int s = it[0];
            int d = it[1];
            int w = it[2];
            if(res[s] != 1e8 && res[d]> res[s]+w) return {-1};
        }
        return res;
    }
};
