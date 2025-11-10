class Solution {
  public:
  // need to Apply DSU to optimize this one
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit){
        
        vector<pair<int , int>>vec;
        int maxDays = 0;
        for(int  i= 0 ;i<profit.size();i++){
            maxDays = max(maxDays , deadline[i]);
            vec.push_back({profit[i] , deadline[i]});
        }
        sort(vec.begin() , vec.end() , greater<>());//Sort - based on the profit - because at the end of the day it is about maximize the profit
        
        vector<bool>taken(maxDays+1 , false); // now to mark if it is visited
        
        int ans = 0;
        int ct = 0;
        for(auto pr : vec){
            bool t = false;
            
            int i = pr.second; // day value
            while(i > 0 && taken[i] == true){ // to check that day or less day we can do that job
                i--;
            }
            
            if(i != 0){
                taken[i] = true;
                ans += pr.first;
                ct++;
            }
        }
        
        return {ct , ans};
        
    }
    
};