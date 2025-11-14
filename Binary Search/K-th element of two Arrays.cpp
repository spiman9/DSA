// Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

// Examples :

// Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
// Output: 6
// Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
// Input: a[] = [1, 4, 8, 10, 12], b[] = [5, 7, 11, 15, 17], k = 6
// Output: 10
// Explanation: Combined sorted array is [1, 4, 5, 7, 8, 10, 11, 12, 15, 17]. The 6th element of this array is 10.


class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int low  = INT_MAX;
        int high = INT_MIN;
        if(a.size() != 0){
            low = min(low , a[0]);
            high = max(high , a[a.size() - 1]);
        }
        
        if(b.size() != 0){
            low = min(low ,b[0]);
            high = max(high , b[b.size() - 1]);
        }
        // cout << low << " " << high << endl;
        k--;
        while(low <= high){
            int mid = (low + high) / 2;
            
            int count = upper_bound(a.begin() , a.end() , mid) - a.begin();
            count +=upper_bound(b.begin() , b.end() , mid) - b.begin();
            
            if(count <= k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
            
            // cout << " low :: " << low << " high :: " << high << " mid :: " << mid << " count :: " << count << endl; 
        }
        return low;
    }
};