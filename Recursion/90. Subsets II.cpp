class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin() , nums.end()); // sorting is important because we are checking side by side
        solve(0 , nums , temp , ans);
        return ans;
    }

    void solve(int ind  , vector<int>&nums , vector<int>&temp , vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int start = ind ; start < nums.size()  ; start++){
            if(start != ind && nums[start] == nums[start-1])continue; // to remove the duplicates from the ans
            // here we will add the ele then call for the start + 1 ind solve method
            temp.push_back(nums[start]);
            solve(start + 1 , nums , temp , ans);
            temp.pop_back();
        }
    }
};