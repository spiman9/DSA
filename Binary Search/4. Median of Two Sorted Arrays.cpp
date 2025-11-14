// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        

        if((n + m) % 2 == 1){
            //odd - means middle element is the ans
            return solve(nums1 , nums2 ,  n ,  m , (n + m) / 2);
        }
        //even - means (n / 2) + (n/2 - 1) divided by this ans is the main ans
        return ((double)solve(nums1 , nums2 ,  n ,  m , (n + m) / 2) + (double)solve(nums1 , nums2 ,  n ,  m , (n + m) / 2 - 1)) / 2;
    }


    int solve(vector<int>& nums1, vector<int>& nums2 , int n , int m , int value){
        int low = INT_MAX;
        int high = INT_MIN;

        if(n!=0){
            low = min(low , nums1[0]);
            high = max(high , nums1[n-1]);
        }

        if(m != 0){
            low = min(low , nums2[0]);
            high = max(high , nums2[m-1]);
        }
        cout << "low :: " << low << " high :: " << high << endl;
        
        while(low <= high){
            int mid = (low + high ) / 2;
            int count = upper_bound(nums1.begin() , nums1.end() , mid) - nums1.begin();
            count += upper_bound(nums2.begin() , nums2.end() , mid) - nums2.begin();

            if(count <= value){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
            cout << "low :: " << low << " high :: " << high << " mid :: " << mid << " Count :: " << count << endl;
        }

        return low;
    }
};