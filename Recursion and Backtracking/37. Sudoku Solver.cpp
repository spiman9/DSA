// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }



    bool solve( vector<vector<char>>& b){
        for(int i = 0 ; i < 9 ; ++i){
            for(int j = 0 ; j < 9 ; j++){
                if(b[i][j] == '.'){
                    //not solved yet this box
                    for(char ch = '1' ; ch <= '9' ;ch++){
                        if(isSafe(i , j , ch , b)){
                            b[i][j] = ch;
                            if(solve(b)){
                                return true;
                            }
                            b[i][j] ='.';
                        }
                    }
                    return false; // impotant this means that the its '.' but no value to fill
                }
            }
        }
        return true; // all the values are been filled in this
    }


    bool isSafe(int row , int col , char ch , vector<vector<char>>&b){

        //same row
        for(int i = 0 ; i <9 ; ++i){
            if(b[row][i] == ch){
                return false;
            }
        }

        //same col
        for(int i = 0 ; i < 9 ; ++i){
            if(b[i][col] == ch){
                return false;
            }
        }

        //check in the same grid
        int rowStart = row / 3 * 3;
        int colStart = col / 3  * 3;
        for(int i = rowStart ; i <= rowStart+2 ; i++){
            for(int j = colStart ; j <= colStart + 2 ; j++){
                if(ch == b[i][j]){
                    return false;
                }
            }
        }

        return true;
    }
};