34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
  
class Solution {
public:
    //You must write an algorithm with O(log n) runtime complexity. That means binary search.
    //Alternative method is to find max and min of nums, seperately
    vector<int> searchRange(vector<int>& nums, int target) {
        return binarySearchRange(nums, target, 0, nums.size()-1);
    }
    
    vector<int> binarySearchRange(vector<int>& nums, int target, int start, int end) {
        if(start > end) return vector<int>{-1, -1};
        if(end - start == 0){ 
            if(nums[start] == target) return vector<int>{start, start};
            else return vector<int>{-1, -1};
        }         
        if(end - start == 1){
            int low = -1, high = -1;
            if(nums[start] == target && nums[end] == target) {low = start; high = end;}
            else if(nums[start] == target) {low = start; high = start;}
            else if(nums[end] == target){low = end; high = end;}
            return vector<int>{low, high};
        }
        
        int mid = (start + end) / 2;
        if(target == nums[mid]){
            int low = mid-1;
            while(low >= start && target == nums[low]) {low--;}
            int high = mid+1;
            while(high <= end && target == nums[high]) {high++;}
            vector<int> res = {low+1, high-1};
            return res;
        }else if( target < nums[mid])
            return binarySearchRange(nums, target, start, mid-1);
        else return binarySearchRange(nums, target, mid+1, end);

    }
};
