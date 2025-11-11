class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int , int>>v;
        
        for(int i = 0 ; i < profit.size(); ++i){
            v.push_back({deadline[i] , profit[i]});
        }
        
        sort(v.begin() , v.end()); // sort based on deadline
        
        
        auto cmp = [](int a , int b){ return a < b;};
        
        priority_queue<int , vector<int> , greater<int> >pq;
        
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i].first > pq.size()){ // this job can be scheduled as its deadline is in future so
            //objvisiosly can be scheduled now
                pq.push(v[i].second);
            }else if(!pq.empty() && pq.top() < v[i].second){
                //job deadline is today or in past we have already consumed the day
                //now we need to remove the lowest profit job and add this one
                pq.pop();
                pq.push(v[i].second);
            }
        }
        
        vector<int>ans = {0,0};
        
        while(!pq.empty()){
            ans[0]++;
            ans[1] += pq.top(); pq.pop();
        }
        
        return ans;
    }
};`