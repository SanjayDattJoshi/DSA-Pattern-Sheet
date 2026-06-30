class Solution {
    
//Memoization Solution
//   public:
//   int fun(vector<int> &arr,vector<vector<int>> &dp, int ind, int prev){
//       if(ind >= arr.size()) return 0;
//       if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
//       int notTake = fun(arr,dp, ind+1, prev);
//       int take=0;
//       if(prev==-1 || arr[ind]>arr[prev]) take = 1+ fun(arr,dp, ind+1, ind);
//       return dp[ind][prev+1] = max(take, notTake);
//   }
  
  
  public:
    int lis(vector<int>& arr) {
        // code here
    
        int n = arr.size();
    //Tabulation solution
    
    //     vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    //     for(int ind=n-1; ind>=0; ind--){
    //         for(int prev=ind-1; prev>=-1; prev--){
    //             int notTake = dp[ind+1][prev+1];
    //             int take=0;
    //             if(prev==-1 || arr[ind]>arr[prev]) take = 1+ dp[ind+1][ind+1];
    //             dp[ind][prev+1] = max(take, notTake);
    //         }
    //     }
    //   return dp[0][0];
    
    //Space Optimized
    
    // vector<int>next (n+1, 0), cur(n+1,0);
        // for(int ind=n-1; ind>=0; ind--){
        //     for(int prev=ind-1; prev>=-1; prev--){
        //         int notTake = next[prev+1];
        //         int take=0;
        //         if(prev==-1 || arr[ind]>arr[prev]) take = 1+ next[ind+1];
        //         cur[prev+1] = max(take, notTake);
        //     }
        //     next = cur;
        // }
        // return next[0];
        
    //More Space Oprtimized (Used to print LIS)
    
    // vector<int> res(n,1); 
    // for(int i=0; i<n; i++){ 
    //     for(int j=0; j<i; j++){ 
    //         if(arr[j]<arr[i]) res[i] = max(res[i], res[j]+1); 
    //     } 
    // } 
    // int maxi = 1; 
    // for(int i=0; i<n; i++) maxi = max(maxi, res[i]); 
    // return maxi;
    // }
    
    
    //Binary Search
    vector<int>temp;
    temp.push_back(arr[0]);
    int len = 1;
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
            len++;
        }
        
        else{
            int ind = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            temp[ind] = arr[i];
        }
    }
    return len;
  }
};
