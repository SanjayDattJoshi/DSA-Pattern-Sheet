class Solution {
public:
    int fun(int n, int m, int guess){
        int ans = 0;
            int row = n-1, col=0;
            while(row>=0 && col<=m-1){
                if((row+1)*(col+1)>guess) row--;
                else{
                    ans += row+1;
                    col = col+1;
                }
            }
    return ans;
    }
  
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m*n;
        int res = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int ans = fun(n, m, mid);
            if(ans<k) low = mid+1;
            else{
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};