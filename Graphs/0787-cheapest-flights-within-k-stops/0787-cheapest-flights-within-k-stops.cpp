class Solution {

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>res(n, 1e8);
        res[src] = 0;
        for(int i=0; i<k+1; i++){
            vector<int> temp = res;
            for(auto it: flights){
                int s = it[0];
                int d = it[1];
                int w = it[2];
                
                if(res[s] != 1e8 && temp[d]> res[s]+w) temp[d] = res[s] + w;
            }
            res= temp;
        }
        return res[dst]==1e8?-1:res[dst];
    }
};