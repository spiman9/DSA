// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool>vis(n , false);
        vector<vector<int>>ans;
        vector<int>temp;
        // solve( nums ,temp, vis , ans);


        solve2(0 , nums  , ans);
        return ans;
    }


    void solve2(int ind , vector<int>&nums , vector<vector<int>>&ans){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }


        for(int start = ind ; start < nums.size() ; start++){
            swap(nums[start] , nums[ind]);
            solve2(ind + 1 , nums , ans);
            swap(nums[start] , nums[ind]);
        }
    }

    

    void solve(vector<int>&nums,vector<int>&temp , vector<bool>&vis , vector<vector<int>>&ans){
        if(temp.size() == vis.size()){
            ans.push_back(temp);
            return;
        }


        for(int start = 0 ; start < vis.size() ; start++){
            if(vis[start] == true) continue;
            temp.push_back(nums[start]);
            vis[start] = true;
            solve(nums , temp , vis , ans);
            vis[start] = false;
            temp.pop_back();
        }
    }
};