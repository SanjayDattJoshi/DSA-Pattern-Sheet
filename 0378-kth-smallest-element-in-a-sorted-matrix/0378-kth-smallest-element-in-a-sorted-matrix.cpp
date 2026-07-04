
//Heap Solution 

// class Node{
// public:
//     int val;
//     int row;
//     int col;
    
// public:
//     Node(int v, int r, int c){
//         val = v;
//         row = r;
//         col = c;
//     }
// };

// class Solution {
// public:
// struct comp{
//     bool operator()(const Node &a, const Node &b){
//         return a.val>b.val;
//     }
// };
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         priority_queue<Node, vector<Node>, comp>pq;
//         for(int i=0; i<n; i++){
//             pq.push({matrix[i][0],i,0});
//         }
//         int cnt = 0, res;
//         while(!pq.empty() && cnt<k){
//             Node cur = pq.top();
//             pq.pop();
//             cnt++;
//             int v = cur.val;
//             int r = cur.row;
//             int c = cur.col;
//             if(cnt==k) return v;
//             if(c<m-1){
//                 pq.push({matrix[r][c+1],r,c+1});
//             }
//         }
//         return 0;
//     }
// };

//Binary Search Solution

class Solution {
public:
int fun(vector<vector<int>> &matrix, int n, int m, int guess){
    int ans = 0;
        int row = n-1, col=0;
        while(row>=0 && col<=m-1){
            if(matrix[row][col]>guess) row--;
            else{
                ans += row+1;
                col = col+1;
            }
        }
    return ans;
}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0], high = matrix[n-1][m-1];
        int res = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int ans = fun(matrix, n, m, mid);
            if(ans<k) low = mid+1;
            else{
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};