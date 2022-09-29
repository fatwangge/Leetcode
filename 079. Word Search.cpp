79. Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
  
Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
  
Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 
Follow up: Could you use search pruning to make your solution faster with a larger board?
  

class Solution {
public:
    //DFS
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++){
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                if(recursive(board, word, 0, i, j, visited)) return true;
            }
        return false;
    }
    
    bool recursive(vector<vector<char>>& board, string &word, int idx, int i, int j, vector<vector<bool>> &visited){
        if(idx == word.length()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if(visited[i][j]) return false;
        if(word[idx] != board[i][j]) return false;
        
        visited[i][j] = true;
        if(recursive(board, word, idx+1, i-1, j, visited) || 
           recursive(board, word, idx+1, i+1, j, visited) ||
           recursive(board, word, idx+1, i, j-1, visited) ||
           recursive(board, word, idx+1, i, j+1, visited))
            return true;
        visited[i][j] = false;  //!
        
        return false; 
    }
}; 
  
  
