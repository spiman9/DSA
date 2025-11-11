
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        int n = g.size();

        sort(s.begin() , s.end());
        int m = s.size();

        int i = 0;// greed
        int j = 0;//cookie size

        int ans = 0;

        while(i <n && j < m){
            //loop
            if(s[j] >= g[i]){
                //we can give cookie
                ans++;
                j++;
                i++;
            }
            else{
                j++; // cookie size increase so that greed can be less
            }
        } 
        return ans;
    }
};