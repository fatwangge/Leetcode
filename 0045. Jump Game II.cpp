45. Jump Game II
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
  
class Solution {
public:
    //Method 1: DP
    //nums: [2,3,1,1,4]
    //dp:   [2,1,2,1,0]
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        vector<int> dp(nums.size(), 0);
        dp[dp.size()-1] = 0;
        dp[dp.size()-2] = 1;
        
        for(int i = nums.size()-3; i >= 0; i--){
            int localMin = INT_MAX-1;
            for(int j = 1; j <= nums[i] && i+j < dp.size(); j++)
                localMin = min(localMin, dp[i+j]);
            dp[i] = localMin + 1;
        }
        
        return dp[0];
    }
    
    //Method 2: Greedy Algorithm, faster
    /*
    int jump(int A[], int n) {
        int max = 0, lastStepMax = 0, step = 0;  
        for(int i = 0; i < n;)  {  
            if(lastStepMax >= n-1) break;  
            
            while(i <= lastStepMax)  {  
                if((i+A[i]) > max) max = i+A[i];  
                i++;  
            }  
            
            step++;  
            lastStepMax = max;              
        }  
        return step;  
    }*/

    //Method 3: Brute force: Exceed time limit
    /*
    void JumpIterate(int A[], int n, int level, int step, int &max){
        if(level >= (n-1)) {
            if(step < max) max = step;
            return;
        }
        
        for(int i = 0; i < A[level]; i++)
            JumpIterate(A, n, level+i+1, step+1, max);
    } */
};
