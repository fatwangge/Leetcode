59. Spiral Matrix II
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:

Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
  
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        int leftBound = 0, rightBound = n-1;
        int upBound = 0, downBound = n-1;
        
        int idx = 1;
        
        while(true){
            for(int i = leftBound; i <= rightBound; i++) res[upBound][i] = idx++;
            upBound++;
            if(upBound > downBound) break;
            
            for(int i = upBound; i <= downBound; i++) res[i][rightBound] = idx++;
            rightBound--;
            if(leftBound > rightBound) break;
                
            for(int i = rightBound; i >= leftBound; i--) res[downBound][i] = idx++;
            downBound--;
            if(upBound > downBound) break;
                
            for(int i = downBound; i >= upBound; i--) res[i][leftBound] = idx++;            
            leftBound++;
            if(leftBound > rightBound) break;
        }
        
        return res;
    }
};
