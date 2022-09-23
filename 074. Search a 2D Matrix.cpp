74. Search a 2D Matrix
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
  
class Solution {
public:
    //Binary search, just convet 2d index to 1d index
    //Example1: target =  3
    //start         end         mid         value
    //0             11          5           11
    //0             4           2           5
    //0             1           =>return true
    //Example2: target = 13
    //start         end         mid         value
    //0             11          5           11
    //6             11          8           23
    //6             7           =>return false
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        int w = matrix[0].size();
        if(h == 1 && w == 1) return matrix[0][0] == target;
        
        int start = 0;
        int end = w*h-1;
        
        while(start <= end){
            if(end-start == 0) return matrix[start/w][start%w] == target;
            if(end-start == 1)
                if(matrix[start/w][start%w] == target || 
                   matrix[end/w][end%w] == target) return true;
                else return false;
            
            int mid = (start + end) / 2;
            int value = matrix[mid/w][mid%w];
            if(value == target) return true;
            else if(value > target) end = mid-1;
            else start = mid+1;
        }
        
        return false;
    }
};
