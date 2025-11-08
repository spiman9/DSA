class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        if(n==1)return 1; // base case

        int i = 1;
        int j = 1;

        while(j < n){
            if(nums[i-1] == nums[j]){
                //skip it
                j++;
            }else{
                nums[i++] = nums[j++];
                ans++;
            }
        }
        return ans;
        
    }
};