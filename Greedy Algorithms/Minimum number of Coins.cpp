// Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10 } and a target value n. Find the minimum number of coins and/or notes needed to make the change for Rs n. 

class Solution { // Greedy Question

  public:
    int findMin(int n) {
        // code here
        int ans = 0;
        
        vector<int>coins = {10 , 5 , 2 , 1};
        
        for(auto x : coins){
            ans += n / x;
            n = n % x;
        }
        return ans;
    }
};