// Given two integers n and m, find the n-th root of m. The n-th root of m is an integer x such that x^n = m. If no such integer exists, return -1.

// Input: n = 3, m = 8
// Output: 2
// Explanation: 23 = 8


class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int left = 1;
        int right = m / 2;
        if(n == 1){
            return m;
        }
        if(m == 0){
            return 0;
        }
        
        if(m == 1){
            return 1;
        }
        
        
        //use the idea of binary search because it is exaustive
        // left = 1
        // right = max ans that can we have that is m
        while(left <= right){ 
            int mid = (left + right) / 2;
            if(pow(mid , n ) == m){
                return mid;
            }else if(pow(mid , n) > m){
                //reduce it
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
    
    
};