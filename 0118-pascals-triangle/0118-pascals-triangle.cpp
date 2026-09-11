class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;

        for(int i=0; i<n; i++){
            vector<int> col;
            for(int j=0; j<=i; j++){
                if(j==0 || j==i){
                    col.push_back(1);
                    continue;
                }
                int row = i-1;
                int col1 = j;
                int col2 = j-1;

                col.push_back(res[row][col1]+res[row][col2]);
            }
            res.push_back(col);
        }
        return res;
    }
};