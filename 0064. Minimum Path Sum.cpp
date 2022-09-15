64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
  
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int width = grid[0].size();
        int height = grid.size();
        vector<vector<int>> dp(height, vector<int>(width, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < width; i++) dp[0][i] = dp[0][i-1] + grid[0][i];
        for(int i = 1; i < height; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i = 1; i < width; i++)
            for(int j = 1; j < height; j++)
                dp[j][i] = min(dp[j-1][i], dp[j][i-1]) + grid[j][i];
        return dp[height-1][width-1];
    }
};
