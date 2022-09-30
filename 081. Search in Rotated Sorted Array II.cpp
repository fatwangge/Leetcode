81. Search in Rotated Sorted Array II
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 
Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 
Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
  
  
class Solution {
public:
    //Method 1: binary search. Because numbers are not distinct, need add one condition
    bool search(vector<int>& nums, int target) {
        return Recursive(nums, target, 0, nums.size()-1);
    }
    
    bool Recursive(vector<int>& nums, int target, int start, int end){
        if(start == end) return target == nums[start];
        if((end - start) == 1) return target == nums[start] || target == nums[end];
        int mid = (start + end) / 2;
        if(target == nums[mid]) return true;
        
        if(nums[start] == nums[mid]) //!this condition is to solve the non-distinct number issue
            //we dont know which side is in order,  and dont know whether the target is in first or second half, so search both
            return Recursive(nums, target, start, mid) || Recursive(nums, target, mid+1, end);
        else if(nums[start] < nums[mid]) //the first half is in order
            if(target >= nums[start] && target <= nums[mid]) //target is in the first half
                return BinarySearch(nums, target, start, mid-1);
            else//target is in the second half
                return Recursive(nums, target, mid+1, end);
        else //the second half is in order
            if(target >= nums[mid] && target <= nums[end]) //target is in the second half
                return BinarySearch(nums, target, mid+1, end);
            else//target is in the first half
                return Recursive(nums, target, start, mid-1);

        return false;
    }
    
    bool BinarySearch(vector<int>& nums, int target, int start, int end){
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] == target) return true;
            if(start == end) return nums[start] == target;
            if((end - start) == 1) return nums[start] == target || nums[end] == target;
            if(target > nums[mid]) start = mid+1;
            else end = mid-1;
        }
        return false;
    }
    
    //Method 2: simple way, supprisingly not slower though
    bool search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target) return true;
        return false;  
    }
    
};
