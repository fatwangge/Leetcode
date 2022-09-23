15. 3Sum
  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

class Solution {
public:
    //Method 1: first sort, the two points
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;  //一个target值只应该用一次。[-4,-1,-1,0,1,2]
            twoSum(nums, i, res);
        }
        return res;
    }
    
    void twoSum(vector<int>& nums, int idx, vector<vector<int>> &res) {
        int i = idx+1, j = nums.size()-1;
        while(i < j){
            int sum = nums[i]+nums[j]+nums[idx];
            if(sum > 0) j--;
            else if(sum < 0) i++;
            else{
                vector<int> oneRes;
                oneRes.push_back(nums[i]);
                oneRes.push_back(nums[j]);
                oneRes.push_back(nums[idx]);
                res.push_back(oneRes);   
                i++; j--;
                while(i < j && nums[i] == nums[i-1]) i++; //[-2,0,0,2,2]
                while(i < j && nums[j] == nums[j+1]) j--;
            }
        }
    }
    
    //Method 2(Error)结果有多种情况，用过的number还可以复用。但triplets不能重复。因此不能用hash table。
    /*
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            vector<int> twoSumRes = twoSum(nums, i);
            if(twoSumRes.size()) res.push_back(twoSumRes);
        }
        return res;
    }
    
    //two sum: find two numbers (except nums[idx]), so that num[i]+num[j]=-num[idx]
    vector<int> twoSum(vector<int>& nums, int idx) {
        unordered_map<int,int> umap;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(i == idx) continue;
            if(umap.find(-nums[i]-nums[idx]) != umap.end()){
                res.push_back(nums[i]);
                res.push_back(-nums[i]-nums[idx]);
                res.push_back(nums[idx]);
                return res;
            }else umap.insert(make_pair(nums[i], i));  
        }
        return res;
    }*/
};
