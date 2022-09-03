35. Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
  
  
class Solution {
public:
    //challenge: You must write an algorithm with O(log n) runtime complexity. Binary search
    int searchInsert(vector<int>& nums, int target) {
        return binarySearchInsertRecursive(nums, target, 0, nums.size()-1); //Method 1: recursive
        //return binarySearchInsertInteration(nums, target, 0, nums.size()-1);//Method 2: iteration
    }
    
    int binarySearchInsertRecursive(vector<int> &nums, int target, int start, int end){
        if(start > end) return start;
        if(start == end) {
            if( nums[start] == target) return start;
            else return nums[start] > target ? start : start + 1;
        }
        if(end-start == 1) {
            if(target <= nums[start]) return start;
            else if(target > nums[end]) return end + 1;
            else return end;
        }
        
        int mid = (start + end)/2;
        if(nums[mid] == target) return mid;
        else if(target < nums[mid]) return binarySearchInsertRecursive(nums, target, start, mid-1);
        else return binarySearchInsertRecursive(nums, target, mid+1, end);
        
    }
    
    int binarySearchInsertInteration(vector<int> &nums, int target, int start, int end){
        while(start <= end){
            if(start == end) {
                if( nums[start] == target) return start;
                else return nums[start] > target ? start : start + 1;
            }
            if(end-start == 1) {
                if(target <= nums[start]) return start;
                else if(target > nums[end]) return end + 1;
                else return end;
            } 
            
            int mid = (start + end)/2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]) end = mid-1;
            else start = mid+1;
        }   
        return start;
    }
};
