// Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N. For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i] will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time. Print the order in which these meetings will be performed.


class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        //main logic it will be based on the endtime when the meeting end if there is start < endtime of current meeting don't start the meetings
        // Your code here
        vector<pair<int , int>>vec;
        for(int i=0;i<start.size();i++){
            vec.push_back({end[i] , start[i]});
        }
        sort(vec.begin() , vec.end());
        //printt(vec);
        int ct = 1;
        int endTime = vec[0].first;
        
        for(int i=1;i<vec.size();i++){
            if(vec[i].second > endTime){
                ct++;
                endTime = vec[i].first;
            }
        }
        
        return ct;
        
        
    }
    
    
    // void printt(vector<pair<int , int>>&vec){
    //     cout << "Print" << endl;
        
    //     for(auto pr : vec){
    //         cout << pr.first << " " << pr.second << endl;
    //     }
    //     cout << endl;
    // }
};