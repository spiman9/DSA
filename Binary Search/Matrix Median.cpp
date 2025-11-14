// Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

// Examples:

// Input: mat[][] = [[1, 3, 5], 
//                 [2, 6, 9], 
//                 [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int low = INT_MAX;
        int high = INT_MIN;
        
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0 ; i < n; i++){
            low = min(low , mat[i][0]);
            high = max(high , mat[i][m-1]);
        }
        int number_of_elemtns_to_the_left_required = n *m / 2;
        //binary search in potential elemts
        while(low <= high){
            int mid = (low + high) / 2;
            
            int number_of_elements_to_the_left = solve(mat , mid , n , m);
            if(number_of_elements_to_the_left <= number_of_elemtns_to_the_left_required){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    
    int solve(vector<vector<int>> & mat , int value , int n , int m){
        int ans = 0;
        for(auto vec : mat){
            //build in methods
            // auto it = upper_bound(vec.begin() , vec.end() , value);
            // ans += it - vec.begin();
            ans = ans + upperBound(vec , value);
        }
        return ans;
    }
    
    //Learn to write a upperbound method
    int upperBound(vector<int>&arr , int value){
        int low = 0;
        int high = arr.size()  - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] > value){
                high = mid - 1;
            }else{ // arr[mid] <= value
                low = mid + 1;
            }
        }
        return low;
    }
};