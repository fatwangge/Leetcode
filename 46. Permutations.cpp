46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
  
class Solution {
public:
    //Analyze: because in permutation you have fixed number of element in every combination. Put an iteration to insert each element
    //example: [1,2,3]
    //first pick 1 => [[1]]            
    //second pick 2 => [[1,2],[2,1]] => to insert 2 to before 1 and after 1, that are 2 positions
    //third pick 3 => [[1,2,3], [2,1,3],[1,3,2],[1,2,3],[3,1,2],[3,2,1]] => to insert 3 in 3 positions
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res{vector<int>{nums[0]}};
        for(int i = 1; i < nums.size(); i++)  
            res = PermuInsert(nums[i], res);
        return res;
    }
    
    vector<vector<int>> PermuInsert(int elem, vector<vector<int>> &inputRes){
        vector<vector<int>> outputRes;

        for(int i = 0; i < inputRes.size(); i++){
            for(int j = 0; j < inputRes[i].size()+1; j++){
                vector<int> oneRes = inputRes[i];
                oneRes.insert(oneRes.begin()+j, elem);
                outputRes.push_back(oneRes);
            }
        }
        
        return outputRes;
    }
};
