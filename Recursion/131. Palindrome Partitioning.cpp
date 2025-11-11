// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;

        vector<string>temp;
        solve(0 , s , temp , ans);
        return ans;
    
    }


    void solve(int ind , string s, vector<string>&temp , vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int start = ind ; start < s.size() ; ++start){
            if(helper(s, ind , start)){
                temp.push_back(s.substr(ind , start - ind + 1));
                solve(start + 1 , s , temp  ,ans);
                temp.pop_back();
            }
        }
    }

    bool helper(string s , int i , int j){
        while(i < j){
            if(s[i] != s[j])return false;
            i++;j--;
        }
        return true;
    }
};