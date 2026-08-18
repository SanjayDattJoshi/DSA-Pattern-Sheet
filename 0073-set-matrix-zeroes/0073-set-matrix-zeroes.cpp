class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool zeroRow = false, zeroCol = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    if(i==0) zeroRow = true;
                    if(j==0) zeroCol = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int k=1; k<n; k++){
            if(matrix[k][0]==0) for(int t=0; t<m; t++) matrix[k][t] = 0;
        }
        for(int k=1; k<m; k++){
            if(matrix[0][k]==0) for(int t=0; t<n; t++) matrix[t][k] = 0;
        }
        if(zeroRow) for(int t=0; t<m; t++) matrix[0][t] = 0;
        if(zeroCol) for(int t=0; t<n; t++) matrix[t][0] = 0;
    }
};