36. Valid Sudoku
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
  
  
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowNum = board.size();
        int colNum = board[0].size();
        
        //check row
        for(int i = 0; i < rowNum; i++){
            bool bDigits[9] = {false};
            for(int j = 0; j < colNum; j++){
                if(board[i][j] == '.') continue;
                if(bDigits[board[i][j]-'1']) return false;
                else bDigits[board[i][j]-'1'] = true;
            }
        }
        
        //check column
        for(int j = 0; j < colNum; j++){
            bool bDigits[9] = {false};
            for(int i = 0; i < rowNum; i++){
                if(board[i][j] == '.') continue;
                if(bDigits[board[i][j]-'1']) return false;
                else bDigits[board[i][j]-'1'] = true;
            }
        }
        
        //check sub-box
        for(int p = 0; p < 3; p++){
            for(int q = 0; q < 3; q++){
                bool bDigits[9] = {false};
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(board[p*3+i][q*3+j] == '.') continue;
                        if(bDigits[board[p*3+i][q*3+j]-'1']) return false;
                        else bDigits[board[p*3+i][q*3+j]-'1'] = true;
                    } 
                }
            }
        }
        
        return true;
    }
};
