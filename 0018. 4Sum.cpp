18. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

class Solution {
public:
    //First double loop, then call two sum(2 pointers), then remove duplicate
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //nlogn
        for(int i = 0; i < nums.size(); i++){ //n^2
            if(i>0 && nums[i] == nums[i-1]) continue; //!to remove duplicate
            for(int j = i+1; j < nums.size(); j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue; //!to remove duplicate
                twoSum(nums, i, j, target, res);
            }
        }
        return res;
    }
    
    void twoSum(vector<int>& nums, int i, int j, int target, vector<vector<int>> &res){
        int k = j+1, l = nums.size()-1;
        while(k < l){
            long long diff = (long long)nums[i]+nums[j]+nums[k]+nums[l]-target; //!use long long to avoid overflow
            if(diff<0) k++;
            else if (diff>0) l--;
            else{
                vector<int> oneRes = vector<int>{nums[i], nums[j], nums[k], nums[l]};
                res.push_back(oneRes);
                k++; l--;
                while(k < nums.size() && nums[k]==nums[k - 1]) k++;  //!to remove duplicate 
                while(l >= 0 && nums[l] == nums[l + 1]) l--; //!to remove duplicate
            }
        }
    }
};
