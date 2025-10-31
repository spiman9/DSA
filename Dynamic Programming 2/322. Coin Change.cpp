class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>>dp(coins.size() , vector<int>(amount+1 , -1));
        // int ans =  solve(coins.size() - 1 , coins , amount ,dp);
        // if(ans >= 1e9)return -1;
        // return ans;

        // Method 2
        vector<vector<int>>dp(coins.size() , vector<int>(amount+1 , 0));
        for(int i = 0 ; i <= amount ; i++){
            if(i%coins[0] == 0){
                dp[0][i] =  i / coins[0];
                continue;
            }
            dp[0][i] = 1e9;
        }

        for(int ind=1;ind<coins.size() ;ind++){
            for(int amt = 0 ; amt <= amount ; amt++){
                // now here calls
                int nottake = 0 + dp[ind - 1][amt];
                int take = 1e9;
                if(coins[ind] <= amt){
                    take = 1 + dp[ind][amt - coins[ind]];
                }
                dp[ind][amt] = min(take , nottake);
            }
        }

        // printDP(dp);

        return dp[coins.size() - 1][amount] < 1e9 ? dp[coins.size() - 1][amount] : -1;
    }

    void printDP(vector<vector<int>>&dp){ //DNU
        for(auto vec : dp){
            for(auto x : vec){
                cout << x << " ";
            }
            cout << endl;
        }
    }

    int solve(int ind ,vector<int>& coins, int amount , vector<vector<int>>&dp){
        if(ind == 0){
            if(amount%coins[0] == 0){
                return amount / coins[0];
            }
            return 1e9;
        }

        if(dp[ind][amount]!= -1){
            return dp[ind][amount];
        }

        // now here calls
        int nottake = 0 + solve(ind - 1 , coins , amount , dp);
        int take = 1e9;
        if(coins[ind] <= amount){
            take = 1 + solve(ind  , coins , amount - coins[ind] , dp);
        }
        return dp[ind][amount] = min(take , nottake);
    }
}