class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>dp(arr.size() , vector<int>(sum + 1 , -1));
        return solve(arr , arr.size()-1 , sum , dp);
    }
    
    bool solve(vector<int>& arr , int ind , int target,vector<vector<int>>&dp){
        if(target == 0){
            return true;
        }
        if(ind == 0){
            return arr[0] == target ? true : false;
        }
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        // not take
        bool nottake = solve(arr , ind - 1 , target , dp);
        bool take = false;
        if(target >= arr[ind])take = solve(arr , ind - 1 , target - arr[ind] , dp);
        return dp[ind][target]  = nottake || take;
    }
};