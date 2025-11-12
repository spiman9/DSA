// Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

// Note: Return the final result vector in lexicographically smallest order.


class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        //UDLR
        //ABC D EFGHIJK L MNOPQ R ST U VWXYZ
        //ORDER --> DLRU
        
        vector<string>ans;
        int row = maze.size();
        int col = maze[0].size();
        vector<vector<bool>>vis(row , vector<bool>(col , false));
        vis[0][0] = true;
        solve(0 , 0 , row , col , maze  , "" , ans,vis);
        return ans;
    }
    
    void solve(int i , int j , int row, int col , vector<vector<int>>&maze , string cur_path , vector<string>&ans,vector<vector<bool>>&vis){
        if(i == row - 1 && j == col - 1){
            //we have reached
            ans.push_back(cur_path);
        }
        
        //validate the boundry condition
        if(i < 0 || j < 0 || i >= row || j >= col){
            return;
        }
        
        vis[i][j] = true; // visited cur node
        
        //down
        if(i+1 < row && !vis[i+1][j] && maze[i+1][j] == 1){
            solve(i + 1 , j , row , col , maze , cur_path + 'D' , ans , vis);
        }
            
            
        //Left
        if(j-1 >= 0 && !vis[i][j-1] && maze[i][j-1] == 1){
            solve(i  , j-1 , row , col , maze , cur_path + 'L' , ans , vis);
        }
            
        
        //Right
        if(j+1 < col && !vis[i][j+1] && maze[i][j+1] == 1){
            solve(i , j+1 , row , col , maze , cur_path + 'R' , ans, vis);
        }
            
            
        if(i-1 >= 0 && !vis[i-1][j] && maze[i-1][j] == 1){
            solve(i - 1 , j , row , col , maze , cur_path + 'U' , ans , vis);
        }
            
        vis[i][j] = false;
        
    }
};