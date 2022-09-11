51. N-Queens.cpp (HARD)

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
  
  
class Solution {
public:
    //Rule: row|, column-, \ and /, queen can not attack
    //Use a vector 'place' to store queen positions
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> place(n, 0);
        recursivePlaceQueen(res, 0, place);
        return res;
    }
    
    void recursivePlaceQueen(vector<vector<string>> &res, int row, vector<int> &place){
        if(row == place.size()){
            vector<string> oneRes;
            for(int i = 0; i < place.size(); i++){
                string queenPos(place.size(), '.');
                queenPos[place[i]] = 'Q';
                oneRes.push_back(queenPos);
            }
            res.push_back(oneRes);
            return;
        }
        
        for(int i = 0; i < place.size() ; i++){ 
            place[row] = i; //try to place row's queen in the ith column
            if(checkValidPosition(place, row)) recursivePlaceQueen(res, row+1, place);
        }
    }
    
    bool checkValidPosition(vector<int> &place, int row){
        for (int i = 0; i < row; ++i){    
            int diff = abs(place[i] - place[row]);    
            if (diff == 0 || diff == row - i)  return false;
        }
        return true; 
    }
};
