73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
  
class Solution {
public:
    //challenge: You must do it in place(no extra space).
    //use the first row and column as aux array
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowZero = false, firstColZero = false;
        for(int i = 0; i < matrix.size(); i++) if(0 == matrix[i][0]) firstColZero = true;
        for(int j = 0; j < matrix[0].size(); j++) if(0 == matrix[0][j]) firstRowZero = true;
        
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[0].size(); j++)
                if(0 == matrix[i][j]) matrix[i][0] = matrix[0][j]= 0;
        
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[0].size(); j++)
                matrix[i][j] = (matrix[i][0] && matrix[0][j]) ? matrix[i][j] : 0;
        
        if(firstColZero) for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        if(firstRowZero) for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
    }
};
