class Solution {
  public:
  //Recursive Solution- 
  
    //   int fun(vector<int> &val, vector<int> &wt, int ind, int W) {

    //     if (ind == val.size())
    //         return 0;

    //     int take = 0;
    //     if (wt[ind] <= W)
    //         take = val[ind] + fun(val, wt, ind + 1, W - wt[ind]);

    //     int notTake = fun(val, wt, ind + 1, W);

    //     return max(take, notTake);
    // }

//Memoization Solution-

//   int fun(vector<int> &v, vector<int> &w,vector<vector<int>> &dp, int ind, int wt){
     
//       if(wt<=0) return 0;
//       if(ind>=v.size()) return 0;
//       if(dp[ind][wt] != -1) return dp[ind][wt];
//       int take = 0;
//       if(wt>=w[ind]) take = v[ind] + fun(v, w,dp, ind+1, wt-w[ind]);
//       int notTake = fun(v, w,dp, ind+1, wt);
      
//       return dp[ind][wt] = max(take, notTake);
//   }

//Tabulation Solution
  public:
    int knapsack(int W, vector<int> &v, vector<int> &w) {
        // code here
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
        for(int ind = n-1; ind>=0; ind--){
            for(int wt=1; wt<=W; wt++){
                int take = 0;
                if(wt>=w[ind]) take = v[ind] + dp[ind+1][wt-w[ind]];
                int notTake = dp[ind+1][wt];
                dp[ind][wt] = max(take, notTake);
            }
        }
        return dp[0][W];
    }
};
