// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;

        vector<string> board;

        string s(n , '.');

        for(int i = 0 ; i< n;i++){
            board.push_back(s);
        }

        solve(0 , board, n , ans);

        return ans;


    }


    void solve(int row , vector<string>&board , int n , vector<vector<string>>&ans){
        if(row == n){
            ans.push_back(board);
        }

        for(int i = 0 ; i< n ; ++i){
            if(isSafe(row , i , board , n)){
                // we are good to put here
                //put it
                board[row][i] = 'Q';
                solve(row + 1 , board , n , ans);
                board[row][i] = '.';
            }
        }
    }

    bool isSafe(int row , int col , vector<string>b , int n){
        // check up  check left Diagonal Check right Diagonal
        int i = 0;
        for(int i = 0 ; i <= row ;++i){
            if(b[i][col] == 'Q')return false;
        }

        int starti = row - 1;
        int startj = col - 1;
        while(starti >=0 && startj >= 0){
            if(b[starti][startj] == 'Q')return false;
            starti--;
            startj--;
        }
        starti = row - 1;
        startj = col + 1;
        while(starti >=0 && startj < n){
            if(b[starti][startj] == 'Q')return false;
            starti--;
            startj++;
        }
        return true;


    }
};


 
