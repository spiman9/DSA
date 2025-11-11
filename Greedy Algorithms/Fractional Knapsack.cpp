class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int , int>>vec;
        for(int i = 0 ; i < wt.size() ;i++){
            vec.push_back({val[i] , wt[i]});
        }
        
        sort(vec.begin() , vec.end() , cmp); // sort based on which is having more val/wt
        
        double ans = 0;
        
        for(auto pr : vec){
            ans += ((double)pr.first / pr.second) * min(capacity , pr.second); // unit * wt
            capacity -= min(capacity , pr.second);
            if(capacity == 0){
                break;
            }
        }
        
        return ans;
        
        
    }
    
    
    static bool cmp(pair<int , int>a , pair<int , int>b){
        return ((double)a.first / a.second) > ((double)b.first / b.second);
    }
};