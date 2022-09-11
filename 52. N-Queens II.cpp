52. N-Queens II (HARD)
  
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:


Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Example 2:

Input: n = 1
Output: 1
  
class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<int> place(n, 0);
        recursivePlaceQueen(res, 0, place);
        return res.size();        
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
