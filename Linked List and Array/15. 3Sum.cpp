class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1])continue; // if 2 elements are same can give duplicate
            vector<int>temp;
            int start = i+1;
            int last = n-1;
            int tar = -1 * nums[i];
            while(start <  last){
                int s = nums[start] + nums[last];
                if(s == tar){
                    //we have found it
                    ans.push_back({nums[i] , nums[start] , nums[last]});
                    //update the start / last ptr
                    start++; // increment start
                    last--; // decrement last
                    while(start < last && nums[start] == nums[start-1]){
                        start++; // until start is same
                    }
                    while(start < last && nums[last] == nums[last+1]){
                        last--; // untile last is same move on
                    }
                }
                else if(s < tar){
                    //req more value
                    start++;
                }else{
                    // s is more reduce the values
                    last--;
                }
            }
        }
        return ans;
    }
};