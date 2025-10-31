class Solution {
public:
    int solve(string s1 , string s2 , int i , int j , vector<vector<int>> &dp){
        if(i <= 0 || j<= 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + solve(s1 , s2 , i-1 , j - 1 ,dp);
        }
        return dp[i][j] = 0 + max(solve(s1 , s2 , i-1 , j , dp) , solve(s1 , s2, i , j-1 , dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp (text1.size()+1 , vector<int>(text2.size()+1 , 0));
        // return solve(text1 , text2, text1.size() ,text2.size() , dp);
        //copy the base case
        int m =text1.size() , n = text2.size();
        vector<int>prev_state(n+1 , 0) , cur_state(n+1 , 0);

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1]){
                    prev_state[j] = 1 +prev_state[j - 1];
                }else{
                    prev_state[j] = 0 + max(prev_state[j] , prev_state[j-1]);
                }
            }
            // prev_state = cur_state;
        }
        return prev_state[text2.size()];
    }
};