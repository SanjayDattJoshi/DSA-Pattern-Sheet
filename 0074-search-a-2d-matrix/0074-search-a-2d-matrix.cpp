class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            pair<int, int> range = {matrix[i][0], matrix[i][m-1]};
            if(target >= range.first && target <= range.second){
                int low = 0, high = m-1;
                while(low <= high){
                   int mid = low + (high -low)/2;
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid]<target){
                        low = mid+1;
                    }
                    else high = mid-1;
                }
                return false;
            }
        }
        return false;
    }
};