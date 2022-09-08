31. Next Permutation
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
  
class Solution {
public:
    //extra challenge: in place
    //the later permutation is larger then the former number, except for the last one
    //ex:
    //1 2 3 4		last two nums are ascending, swap the last two nums
    //1 2 4 3		last two nums are decending; the last 3rd(2) and 2nd(4) nums are ascending, swap (2) and (3), because (3) is the smallest(but > 2) in (4,3) sequence
    //1 3 2 4		last two nums are ascending, swap the last two nums
    //1 3 4 2		last two nums are decending; the last 3rd and 2nd nums are ascending, swap (3) and (4), because (4) is the smallest(but > 3) in (4,2) sequence
    //1 4 2 3		last two nums are ascending, swap the last two nums
    //1 4 3 2		last two nums are decending; last three nums are decending; the last 4th(1) and 3rd(4) nums are ascending; swap (1) and (2), because (2) is the smallest(but > 1) in (4,3,2) sequence
    //2 1 3 4
    //2 1 4 3
    //2 3 1 4
    //2 3 4 1
    //2 4 1 3
    //2 4 3 1
    //3...
    //Algorithm: from the back to front, find the place of ascending(value a), then the smallest num(but > a) after (a), let's say it is b, swap(a,b). Then sort nums after (b)
    //if ascending can't be found, sort all nums
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size()-1; i >= 1; i--){
            if(nums[i-1] < nums[i]){ //find the place of ascending
                int j = nums.size()-1;
                while(nums[i-1] >= nums[j]) j--;
                swap(nums[i-1], nums[j]);//swap nums[i-1] and another nums[j], which is smallest but also nums[i-1] < nums[j]
                sort(nums.begin()+i, nums.end());
                break;
            }
            if(i == 1) sort(nums.begin(), nums.end());
        }
    }
};
