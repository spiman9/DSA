class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int i = 0;
        int ct = 0;
        while(i < nums.size()){
            if(nums[i] == 0){
                ct = 0;
                i++;
                continue;
            }else if(i == 0){
                ct = 1;
                ans = max(ans , ct);
            }else{
                ct++;
                ans = max(ans , ct);
            }
            i++;
        }
        return ans;
    }
};