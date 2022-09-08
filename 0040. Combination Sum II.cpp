40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 
Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
  
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> oneRes;
        sort(candidates.begin(), candidates.end());
        recursive(candidates, target, res, oneRes, 0, 0);
        return res;
    }
    
    void recursive(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &oneRes, int index, int sum){
        if(sum == target){
            res.push_back(oneRes);
        }else if(sum < target){
            for(int i = index; i < candidates.size(); i++){
                oneRes.push_back(candidates[i]);
                sum += candidates[i];
                recursive(candidates, target, res, oneRes, i+1, sum);
                sum -= candidates[i];
                oneRes.pop_back();
                
                //To ensure elem is used at least once, the following line must be put in the end
                while((i+1) < candidates.size() && candidates[i] == candidates[i+1]) i++; 
            }
        }
    }
    
};  
  
  
