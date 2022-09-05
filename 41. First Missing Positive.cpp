41. First Missing Positive (HARD)
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
  
class Solution {
public:
    //Analyze: to construct an array, which array[i] = i+1. The first missing elem in this array is the answer
    //To make it O(n) and no extra space, interate the nums, each time swap one elem to the correct position.
    //Example 1:
    //id = 0, [3,4,-1,1], slot0 is 3, swap 3 and -1 => this is to ensure 3 in the correct position
    //id = 0, [-1,4,3,1], slot0 is non-positive: -1, id++ => -1 has no correct position, leave it unchange
    //id = 1, [-1,4,3,1], slot1 is 4, swap 4 and 1 => this is to ensure 4 in the correct position
    //id = 1, [-1,1,3,4], slot1 is non-positive: 1, swap 1 and -1 => this is to ensure 1 in the correct position
    //id = 1, [1,-1,3,4], slot1 is -1, id++
    //id = 2, [1,-1,3,4], slot2 is 3, because 3 is in correct position, id++
    //id = 3, [1,-1,3,4], slot3 is 4, because 4 is in correct position, id++
    //Example 2:
    //id = 0, [1,2,0], slot0 is 1, because 1 is in correct position, id++
    //id = 1, [1,2,0], slot1 is 2, because 2 is in correct position, id++
    //id = 2, [1,2,0], slot2 is 0, because this is non-positive: 0, id++
    int firstMissingPositive(vector<int>& nums) {
        int id = 0;
        while(id < nums.size()){
            if(nums[id] > 0 && nums[id] < nums.size() && nums[nums[id] - 1] != nums[id]){
                swap(nums[id], nums[nums[id] - 1]);
            }else id++;
        }
        for(int i = 0; i< nums.size(); i++)
            if(nums[i] != i+1) return i+1;
        return nums.size() + 1;
    }
};
