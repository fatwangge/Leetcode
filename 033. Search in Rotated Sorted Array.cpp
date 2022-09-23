33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
  
class Solution {
public:
    //Method 1: binary search. 3~4ms
    int search(vector<int>& nums, int target) {
        return searchRecursive(nums, target, 0, nums.size()-1);    //the end is the last index of nums
    }
    
    int searchRecursive(vector<int>& nums, int target, int start, int end){
        if(start > end) return -1;
        if(end - start == 0) return nums[start] == target ? start : -1;
        if(end - start == 1) {
            if(nums[start] == target) return start;
            else if(nums[start+1] == target) return start+1;
            else return -1;
        }
        
        int mid = (start + end) / 2; 
        if(nums[start] < nums[mid]) {
            if(target >= nums[start] && target <= nums[mid]) return binarySearch(nums, target, start, mid);
            else return searchRecursive(nums, target, mid+1, end);
        }
        else{ // if(nums[mid] < nums[end] ) 
            if(target >= nums[mid] && target <= nums[end]) return binarySearch(nums, target, mid, end);
            else return searchRecursive(nums, target, start, mid-1);
        }
        
        return -1;
    }
    
    int binarySearch(vector<int>& nums, int target, int start, int end){
        while(start <= end){
            int mid = (start + end) / 2;
            if(target == nums[mid]){
                return mid;
            }else if (target < nums[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return -1;         
    }
    
    
    //Method 2: simple way... 8~13ms
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target) return i;
        return -1;    
    }
};

  
