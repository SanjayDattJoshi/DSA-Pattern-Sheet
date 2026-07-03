class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        //2-Time BS
        // int l = 0, h = n-1;
        // while(l<=h){
        //     int middle = l + (h-l)/2;
        //     if(matrix[middle][m-1]<target) l = middle+1;
        //     else if(matrix[middle][0]>target) h = middle-1;
        //     else{
        //         int low = 0, high = m-1;
        //         while(low <= high){
        //            int mid = low + (high -low)/2;
        //             if(matrix[middle][mid]==target) return true;
        //             else if(matrix[middle][mid]<target){
        //                 low = mid+1;
        //             }
        //             else high = mid-1;
        //         }
        //         return false;
        //     }
        // }
        // return false;

        //1-Time BS
        int low = 0, high = n*m-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int row = mid/m, col = mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};