class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(begin(nums) , end(nums) , 0);
        if(total % 2 ==1)return false;
        int n = nums.size();
        int target = total / 2;
        vector<vector<int>>dp(n , vector<int>(target + 1 , -1));
        int ans = solve(n-1 , target,nums,dp);
        return ans == -1 ? 0 : ans;
    }

    int solve(int ind , int t,vector<int>& nums,vector<vector<int>>&dp){
        if(ind == 0){
            return nums[0] == t || t == 0 ?  1 : 0;
        }
        if(t == 0)return 1;
        
        int nottake = solve(ind - 1 , t , nums ,dp);
        int take = false;
        if(dp[ind][t] != -1){
            return dp[ind][t];
        }
        if(nums[ind] <= t){
            take = solve(ind - 1 , t - nums[ind] , nums ,dp);
        }
        return dp[ind][t] = take || nottake;
    }


};