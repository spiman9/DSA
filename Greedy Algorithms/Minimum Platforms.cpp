Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900).




/// Approch two Optimal approach to solve the question

// Coding ninjas
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at , at+n);    
    sort(dt  , dt + n);

    int Number_of_platforms = 0;
    int curr_number_of_trains = 0;

    int i = 0;
    int j = 0;
    while(i < n){
        if(at[i] <= dt[j]){ // means aniother train arrived
            i++;
            curr_number_of_trains++;
            Number_of_platforms = max(curr_number_of_trains , Number_of_platforms);
        }else{
            //means that train is departing
            curr_number_of_trains--;
            j++;
        }
    }

    return Number_of_platforms;

}




// Approch one Brute force to solve the question - Done in O(n^2) time complexity
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<pair<int , int>>vec;
        int ans = 0;
        
        for(int i = 0 ; i < arr.size() ; i++){
            vec.push_back({arr[i] , dep[i]});
        }
        
        sort(vec.begin() , vec.end());
        
        while(vec.size() != 0){
            ans++;
            pair<int , int>last = vec[0];
            vector<bool>remv(vec.size() , false);
            remv[0] = true;
            
            
            for(int i = 1 ; i <vec.size() ; i++){
                auto pr = vec[i];
                if(last.second < pr.first){
                    //remove it
                    remv[i] = true;
                    last = pr;
                }
            }
            
            vector<pair<int , int>>temp;
            for(int i=0;i<vec.size();i++){
                if(!remv[i]){
                    //remove it from array
                    temp.push_back(vec[i]);
                }
            }
            vec = temp;
        }
        return ans;
        
        
    }
};



