16. 3Sum Closest.cpp

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
 

Constraints:

3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104
  
  
class Solution {
public:
    //similar to 3sum, first sort and then two pointers
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        int diff = INT_MAX;
        for(int k = 0; k < nums.size(); k++){
            int i = k+1, j = nums.size()-1;
            while(i < j){
                int sum = nums[i] + nums[j] + nums[k];
                int curDiff = abs(sum-target);
                if(curDiff < diff){
                    diff = curDiff;
                    res = sum;
                }
                if(sum > target) j--;
                else if (sum < target) i++;
                else return res;
            }
        }
        return res;
    }
};  
