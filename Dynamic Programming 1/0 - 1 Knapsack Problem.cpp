class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        // method one
        // vector<vector<int>>dp(n , vector<int>(W + 1  , -1));
        // return solve(n-1, W, val, wt , dp);
        
        // method 2
        vector<vector<int>>dp(n , vector<int>(W + 1  , 0));
        
        // base condition
        for(int i=0;i<=W;i++){
            if(wt[0] <= i){
                dp[0][i] = val[0];
            }
        }
        // forloops
        for(int i=1;i<n;i++){
            for(int w = 0; w<=W;w++){
                int nottake = 0 + dp[i - 1][w];
                int take = 0;
                if(wt[i] <= w){
                    take = dp[i - 1][w - wt[i]] + val[i];
                }
                dp[i][w] = max(take , nottake);
            }
        }
        
        // printDP(dp);
        
        return dp[n-1][W];
    }
    
    void printDP(vector<vector<int>>&dp){
        for(auto vec : dp){
            for(auto x : vec){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    
    
    int solve(int n ,int W, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if(n == 0){
            // last nex
            if(wt[0] <= W){
                return val[0];
            }
            return 0;
        }
        
        // now here the recursive calls
        // take it
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        int nottake = 0 + solve(n - 1 , W , val , wt , dp);
        int take = 0;
        if(wt[n] <= W){
            take = solve(n -1 , W - wt[n] , val , wt , dp) + val[n];
        }
        return dp[n][W] = max(take , nottake);
    }
};