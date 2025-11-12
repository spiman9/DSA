// Word Break - Find All Ways to Break
// Last Updated : 12 Jul, 2025
// Given a non-empty string s and a dictionary dict[] containing a list of non-empty words, the task is to return all possible ways to break the string in individual dictionary words.
// Note: The same word in the dictionary may be reused multiple times while breaking.

// Input: s = "likegfg" , dict[] = ["lik", "like", "egfg", "gfg"]
// Output: 
// "lik egfg" 
// "like gfg"
// Explanation: The string "likegfg" is segmented into valid dictionary words in all possible ways: "lik egfg" and "like gfg".


// User function Template for C++
class Solution {
  public:
    vector<string> wordBreak(vector<string>& dict, string& s) {
        // code here
        vector<string>ans;
        vector<string>temp;
        solve("" , s , dict , ans , temp);
        return ans;
    }
    
    
    void solve(string cur , string &target , vector<string>&dict , vector<string>&ans , vector<string>&temp ){
        if(cur == target){
            //we found the ans
            string t = "";
            for(auto substr : temp){
                if(t == ""){
                    t = substr;
                }
                else{
                    t += " " + substr;
                }
            }
            ans.push_back(t);
            return;
        }
        
        
        for(int i = 0 ; i < dict.size() ; i++){
            string newS = cur + dict[i];
            if(newS.size() <= target.size() && newS == target.substr(0 , newS.size())){
                //it means it is a substring
                temp.push_back(dict[i]);
                solve(newS , target , dict , ans , temp);
                temp.pop_back();
            }
        }
    }
};