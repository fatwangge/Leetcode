85. Maximal Rectangle (HARD)
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 
Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
  

class Solution {
public:
    /*Use function in Largest Rectangle in Histogram*/
    //height for the example:
    //1 0 1 0 0
    //2 0 2 1 1
    //3 1 3 2 2
    //4 0 0 3 0
    //calculate for the example, for each height row:
    //r_0 = 1
    //r_1 = 3*1 = 3
    //r_2 = 3*2 = 6
    //r_3 = 4
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();/*!!!!forgot [0]!!!!*/
        vector<vector<int>> height;
        
        for(int i = 0; i < m ;i++){
            vector<int> row;
            height.push_back(row);
            /*Construct height. Each row is a histogram*/
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0') height[i].push_back(0);
                else if(i == 0) height[i].push_back(1);
                else height[i].push_back(height[i-1][j]+1);
            }
        }
        
        int maxResult = 0;
        for(int i = 0; i < m; i++){
            int r = largestRectangleArea(height[i]);
            if(r > maxResult) maxResult = r;
        }

        return maxResult;
    }
    
    int largestRectangleArea(vector<int> height) {
        vector<int> stack;
        height.push_back(0);
        int result = 0;
        
        for(int i = 0; i < height.size(); i++){
            if(stack.empty() || height[stack.back()] < height[i]){
                stack.push_back(i);
            }else{
                int top = stack.back();
                stack.pop_back();
                
                int length;
                if(stack.empty()) length = i;
                else length = i - stack.back() - 1;
                
                result = max(result, height[top] * length);
                i--;
            }
        }
        
        return result;
    }
};
