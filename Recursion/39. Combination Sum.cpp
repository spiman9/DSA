class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end()); //for unique combinations
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0 , target  , candidates , temp , ans);
        return ans;
    }

    void solve(int ind , int t , vector<int>&arr , vector<int>&temp , vector<vector<int>>&ans){
        if(t == 0){
            ans.push_back(temp);
            return;
        }


        // recursive calls
        for(int start = ind ; start < arr.size() ; start++){
            if(start != ind && arr[start - 1] == arr[start])continue;
            if (arr[start] <= t){
                temp.push_back(arr[start]);
                solve(start , t - arr[start] , arr , temp , ans);
                temp.pop_back();
            }
        }
    }