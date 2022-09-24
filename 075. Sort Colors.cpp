75. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 
Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
  
class Solution {
public:
    //in place, one-pass algorithm
    //Example: [2,0,2,1,1,0]
    //p1,[2,0,2,1,1,0],p2
    //p1,[2(p),0,2,1,1,0],p2
    //p1,[0(p),0,2,1,1,2(p2)]
    //[0(p1,p),0,2,1,1,2(p2)]
    //[0(p1),0(p),2,1,1,2(p2)]
    //[0,0(p1,p),2,1,1,2(p2)]
    //[0,0(p1),2(p),1,1,2(p2)]
    //[0,0(p1),1(p),1,2(p2),2]
    void sortColors(vector<int>& nums) {
        int p = 0, p1 = -1, p2 = nums.size();
        while(p < p2){  
            if(nums[p] == 0) swap(nums[p++],nums[++p1]);
            else if(nums[p] == 1) p++;
            else swap(nums[p],nums[--p2]);
        }
    }
};
  
  
  
