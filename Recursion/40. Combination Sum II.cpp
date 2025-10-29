class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin() , candidates.end());
        solve(0 ,target , candidates , ans, temp );
        return ans;
    }

    void solve(int ind , int t , vector<int>&nums , vector<vector<int>>&ans , vector<int>&temp){
        if(t == 0){
            ans.push_back(temp);
            return;
            // we got the ans
        }

        // recur calls
        for(int start = ind  ; start < nums.size() ; start++){
            if(ind != start && nums[start - 1] == nums[start]){
                // already can raise to duplicates
                continue;
            }
            if(nums[start] <= t){
                // then only take
                temp.push_back(nums[start]);
                solve(start + 1 , t - nums[start] , nums , ans , temp);
                temp.pop_back();
            }
        }
    }
};